# int main(){
# 	int i=3, j=5, n=2, m=8;

# 	A(i,j,n,m);
# 	return 0;
# }

# int A(int i, int j, int n, int m){
# 	return B(i,n) + B(j,m);
# }

# int B(int i, int n){
# 	return i*n;
# }


# Main
main:
	li		$s0, 3		# $s0 = int i = 3
	li		$s1, 5		# $s1 = int i = 5
	li		$s2, 2		# $s2 = int i = 2
	li		$s3, 8		# $s3 = int i = 8
	
	# Setting arguments
	move 	$a0, $s0	# $a0 = i
	move 	$a1, $s1	# $a1 = j
	move 	$a2, $s2	# $a2 = n
	move 	$a3, $s3	# $a3 = m

	# A(i, j, n, m)
	# Stack snapshot 1
	jal A_func # Stack snapshot 2
	# Stack snapshot 9
	# Don't have to save $v0 because it is also not saved in the int main()

	j Exit

# Function A
A_func:
	# Stack snapshot 2
	
	# $a0 = i, $a1 = j, $a2 = n, $a3 = m

	# Store arguments j and n, because they have to be moved around for new arguments
	# m does not have to be stored, since B_func will not interact with $a3
	# $a0 = i so that is fine for first B_func call: it does not have to be stored
	move 	$t0, $a1			# 	$t0 = j
	move 	$t1, $a2			# 	$t1 = n
	# Don't know if it is handy that we don't save $a3, but in this case it works
	# I don't know MIPS coventions


	# Push $ra because of upcoming nested function call
	sub		$sp, $sp, 4 
	sw		$ra, 0($sp)

	# load second argument (n) for B_func
	# $a0 = i so that is fine for first B_func call
	# B(i, n)
	move 	$a1, $t1			# $a1 = n

	# Stack snapshot 3
	jal		B_func				# Stack snapshot 4
	# Stack snapshot 5
	move 	$t3, $v0			# $t3 = B(i,n)

	# B(j, m)
	move 	$a0, $t0			# $a0 = j
	move 	$a1, $a3			# $a1 = m
	# Stack snapshot 6
	jal 	B_func				# Stack snapshot 7
	# Stack snapshot 8
	move 	$t4, $v0			# $t4 = $v0

	add		$v0, $t3, $t4		# $v0 = B(i,n) + B(j,m)

	# Pop $ra
	lw		$ra, 0($sp)
	addi	$sp, $sp, 4 

	jr		$ra					# jump to $ra


# Function B
B_func:
	# Stack snapshots 4 and 7
	# $a0 = i, $a1 = n
	mult	$a0, $a1			# $a0 * $a1 = Hi and Lo registers
	mflo	$v0					# copy Lo to $v0
	# No overflow check, because how to do error checking?
	jr		$ra					# jump to $ra

Exit:
