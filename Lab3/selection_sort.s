		.text
		j	main			# Jump to main-routine

		.data
str1:		.asciiz "Insert the array size \n"
str2:		.asciiz "Insert the array elements,one per line  \n"
str3:		.asciiz "The sorted array is : \n"
str5:		.asciiz "\n"

		.text
		.globl	main
main: 
		la	$a0, str1		# Print of str1
		li	$v0, 4			#
		syscall				#

		li	$v0, 5			# Get the array size(n) and
		syscall				# and put it in $v0
		move	$s2, $v0		# $s2=n
		sll	$s0, $v0, 2		# $s0=n*4
		sub	$sp, $sp, $s0		# This instruction creates a stack
						# frame large enough to contain
						# the array
		la	$a0, str2		#
		li	$v0, 4			# Print of str2
		syscall				#
            
		move	$s1, $zero		# i=0
for_get:	
		bge	$s1, $s2, exit_get	# if i>=n go to exit_for_get
		sll	$t0, $s1, 2		# $t0=i*4
		add	$t1, $t0, $sp		# $t1=$sp+i*4
		li	$v0, 5			# Get one element of the array
		syscall				#
		sw	$v0, 0($t1)		# The element is stored
						# at the address $t1
		la	$a0, str5
		li	$v0, 4
		syscall
		addi	$s1, $s1, 1		# i=i+1
		j	for_get
exit_get:	
		move	$a0, $sp		# $a0=base address af the array
		move	$a1, $s2		# $a1=size of the array
		jal	selection_sort			# selection_sort(a,n)
						# In this moment the array has been 
						# sorted and is in the stack frame

		# test swap
		# move $a0, $sp
		# li   $a1, 0
		# li	 $a2, 2 
		# jal swap
		######################

		# test index_minimum
		# move $a0, $sp
		# li   $a1, 0
		# li   $a2, 2 
		# jal index_minimum

		# move $a0, $v0
		# li	$v0, 1
		# syscall

		# move $a0, $sp
		# li   $a1, 1
		# li   $a2, 3 
		# jal index_minimum

		# move $a0, $v0
		# li	$v0, 1
		# syscall
		#####################

		move	$s1, $zero		# i=0

		j for_print				# jump to for_print
		

selection_sort:
		# $a0 = a[], $a1 = length
		# $s0 = i, $s1 = mini, $s2 = length - 1
		
		sub		$sp, $sp, 16		# push $s0 - $s2, $ra onto stack
		sw		$s0, 0($sp)			# 
		sw		$s1, 4($sp)			# 
		sw		$s2, 8($sp)			# 
		sw		$ra, 12($sp)		# 

		move	$s0, $zero			# i = 0
		addi	$s2, $a1, -1		# $s2 = length - 1
		
_selection_sort_for:
		bge		$s0, $s2, _selection_sort_exit
		
		move $a0, $a0
		move $a1, $s0		# load i and lenght-1 in arguments. a is already in $a0
		move $a2, $s2 		#
		jal index_minimum 	# call index_minimum
		move $s1, $v0 		# mini = return value

		move $a0, $a0
		move $a1, $s0
		move $a2, $s1 		# load mini into $a2, other arguments have already been set
		jal swap

		j _selection_sort_for

_selection_sort_exit:
		lw		$s0, 0($sp)			# pop $s0 - $s2, $ra from stack
		lw		$s1, 4($sp)			# 
		lw		$s2, 8($sp)			# 
		lw		$ra, 12($sp)		# 
		add		$sp, $sp, 16		# 

		jr		$ra	
		
index_minimum:
		# $a0 = v[], $a1 = first, $a2 = last
		# $s0 = i, $s1 = min, $s2 = mini

		sub		$sp, $sp, 12		# push $s0 - $s2 onto stack
		sw		$s0, 0($sp)			# 
		sw		$s1, 4($sp)			# 
		sw		$s2, 8($sp)			# 
		
		move $s2, $a1 	# mini = first
		
		sll $t0, $a1, 2		# min = v[first]
		add $t1, $a0, $t0	#
		lw $s1, 0($t1)		#

		move $s0, $a1		# i = first + 1
		addi $s0, $s0, 1	#

_index_minimum_for:
		bgt		$s0, $a2, _index_minimum_exit	# for loop condition
		
		sll $t0, $s0, 2		# $t2 = v[i]
		add $t1, $a0, $t0	#
		lw $t2, 0($t1)		#

		bge $t2, $s1, _index_miminum_endif

		#if v[i] < min
		move $s2, $s0 		# mini = i
		move $s1, $t2 		# min = v[i]

_index_miminum_endif:
		addi	$s0, $s0, 1			# i++
		j _index_minimum_for

_index_minimum_exit:
		move $v0, $s2				# return mini

		lw		$s0, 0($sp)			# pop $s0 - $s2 from stack
		lw		$s1, 4($sp)			# 
		lw		$s2, 8($sp)			# 
		add		$sp, $sp, 12		# 

		jr		$ra					# jump to $ra
		
swap:
		# $a0 = v[], $a1 = i, $a2 = j
		
		# $t2 = v[i], $t1 = &v[i]
		sll		$t0, $a1, 2			# $t0 = $a1 << 2
		add		$t1, $a0, $t0		# get address of v[i]
		lw		$t2, 0($t1)			
		
		# $t4 = v[j], $t3 = &v[j]
		sll		$t0, $a2, 2			# $t0 = $a2 << 2
		add		$t3, $a0, $t0		# get address of v[j]
		lw		$t4, 0($t3)			
		
		move 	$t0, $t2		# $t0 = v[i]
		sw		$t4, 0($t1)		# store v[j] at address of v[i] 
		sw		$t0, 0($t3)		# store $t0 at address of v[j]
		
		jr 	$ra

for_print:	
		bge	$s1, $s2, exit_print	# if i>=n go to exit_print
		sll	$t0, $s1, 2		# $t0=i*4
		add	$t1, $sp, $t0		# $t1=address of a[i]
		lw	$a0, 0($t1)		#
		li	$v0, 1			# print of the element a[i]
		syscall				#

		la	$a0, str5
		li	$v0, 4
		syscall
		addi	$s1, $s1, 1		# i=i+1
		j	for_print

exit_print:	
		add	$sp, $sp, $s0		# elimination of the stack frame       
		li	$v0, 10			# EXIT
		syscall				#
