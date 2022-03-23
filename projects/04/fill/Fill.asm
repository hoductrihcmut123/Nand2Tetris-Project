// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(begin)		// Kiểm tra ô nhớ KBD xem có phím nào được ấn k ?
@KBD
D=M
@white
D;JEQ
@black
D;JNE


(white)		// K có phím dc ấn
@count		// tạo biến đếm count=0
M=0
(loopwhite)	// vòng lặp để set white
@count
D=M
@SCREEN
A=A+D
M=0		// set white
@count		// cout++
M=M+1
D=M
@8192		// ô nhớ KBD-SCREEN ( 24576- 16384 )
D=D-A
@loopwhite	// if(count-8192 != 0) return loopwhite
D;JNE
@begin
0;JMP

(black)		// Có phím dc ấn
@count		// tạo biến đếm count=0
M=0
(loopblack)	// vòng lặp để set black
@count
D=M
@SCREEN
A=A+D
M=-1		// set black
@count		// count++
M=M+1
D=M
@8192		// ô nhớ KBD-SCREEN
D=D-A
@loopblack	// if(count-8192 != 0) return loopblack
D;JNE
@begin
0;JMP










