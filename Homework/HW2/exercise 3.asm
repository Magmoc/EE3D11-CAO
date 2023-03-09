# for(int i = 0; i < 100; i++)
# 	if(A[i] != B[i]) count++;

# $S0 = i
# $S1 = count
# $S2 = A
# $S3 = B

# $t0 = 4*i
# $t1 = A[i]
# $t2 = B[i]
# $t3 stores address of A[i] or B[i]


li $s0, 0

loop:
	beq $S0, 100, exit	
# load A
	sll $t0, $S0, 2
	add $t3, $t0, $s2
	lw $t1, 0($t3)
# load B
	add $t3, $t0, $s3
	lw $t2, 0($t3)

# If B != A
	bne $t1, $t2, inccount
	j skip
inccount:
	addi $s1, $s1, 1
skip:
	addi $s0, $s0, 1	
	j loop
exit:
