ori $s0, $0, 3
ori $s1, $0, -2
ori $s2, $0, 420
ori $s3, $0, -69
nor $s4, $0, $0

ori $t0, $0, 1
ori $t1, $0, 1
ori $t2, $0, 1
ori $t3, $0, 1
sllv $t0, $s4, $s0
sllv $t1, $s4, $s1
sllv $t2, $s4, $s2
sllv $t3, $s4, $s3

sllv $t4, $t2, $s2
