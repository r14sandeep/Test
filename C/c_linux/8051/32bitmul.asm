CSEG AT 0
N1 EQU 0FFFFFFFFH
N2 EQU 0FFFFFFFFH
MOV A,#N1
MOV B,#N2
MUL AB
MOV R7,A
MOV R6,B
MOV A,N1>>8
MOV B,#N2
MUL AB
ADDC A,R6
MOV R6,A
MOV R5,B
MOV A,#N1>>16
MOV B,#N2
MUL AB
ADDC A,R5
MOV R5,A
MOV R4,B
MOV A,#N1>>24
MOV B,#N2
MUL AB
ADDC A,R4
MOV R4,A
MOV R3,B

/*MOV A,#N1
MOV B,#N2>>8
MUL AB
ADDC A,R6
MOV R5,B
MOV A,#N1>>8
MOV B,#N2>>8
MUL AB
ADDC A,R5
MOV R5,A
ADDC B,R4
MOV R4,B
MOV A,#N1>>16
MOV B,#N2>>8
MUL AB
ADDC A,R4
MOV R4,A
ADDC B,R3
MOV R3,B
MOV A,#N1>>32
MOV B,#N2>>8
MUL AB
ADDC A,R3
MOV R3,A
MOV R2,B
MOV A,#N1
MOV B,#N2>>16
ADDC A,R5
MOV R5,A
ADDC B,R4
MOV R4,B
MOV A,#N1>>8
MOV B,#N2>>16
ADDC A,R4
MOV R4,A
ADDC B,R3
MOV R3,B
MOV A,#N1>>16
MOV B,#N2>>16
ADDC A,R3
MOV R3,A
ADDC B,R2
MOV R2,B
MOV A,#N1>>32
MOV B,#N2>>16
ADDC A,R3
MOV R2,A
MOV R1,B
MOV A,#N1
MOV B,#N2>>32
ADDC A,R4
MOV R4,A
ADDC B,R3
MOV R3,B
MOV A,#N1>>8
MOV B,#N2>>32
ADDC A,R3
MOV R3,A
ADDC B,R2
MOV R2,B
MOV A,#N1>>16
MOV B,#N2>>32
ADDC A,R2
MOV R2,A
ADDC B,R1
MOV R1,B
MOV A,#N1>>32
MOV B,#N2>>32
ADDC A,R1
MOV R1,A
MOV R0,B

*/
END

