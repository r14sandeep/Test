CSEG AT 0
MOV R0,#0ffH
MOV R1,#23H
MOV R2,#56H
MOV R3,#0ffH
MOV A,R0
RLC A
MOV R0,A
MOV A,R3
RLC A
MOV R3,A
MOV A,R2
RLC A
MOV R2,A
MOV A,R1
RLC A
MOV R1,A
MOV A,R0
MOV ACC.0,C
mov r0,a
END
