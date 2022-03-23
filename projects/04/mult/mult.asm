// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

@result			// result=0
M=0			
@count			// count=0
M=0

(LOOP)
@count			// so sánh điều kiện
D=M
@1
D=D-M
@END
D;JEQ			// if (count-R1==0) return END
@0
D=M
@result			// result= result+ R0
M=M+D
@count			// count++
M=M+1
@LOOP
0;JMP

(END)
@result			// gán R2=result
D=M
@2
M=D