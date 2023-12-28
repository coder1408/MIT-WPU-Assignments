%macro scall 4   ; Define a macro named scall with 4 parameters
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
Number dw 9999d   ; Define a decimal number (word size) to convert
msg db 10d,13d, "Equivalent HEX Number is: "   ; Define a message string terminated by newline characters (10d, 13d)
msgLen equ $-msg   ; Calculate the length of the message string

section .bss
num resb 5   ; Reserve space for a byte array named num with a size of 5 bytes

section .text
global _start
_start:
mov ax, word[Number]   ; Load the decimal number into the ax register
mov bx, 10H   ; Set bx to 16 (hexadecimal base)
mov rdi, num+4   ; Set the destination index to the end of the num array

loop3:
mov dx, 0   ; Clear the dx register
div bx   ; Divide ax by bx, quotient in ax, remainder in dx
cmp dl, 09h   ; Compare the remainder with 9
jbe down1   ; Jump to down1 label if less than or equal (not greater)
add dl, 07h   ; Add 7 to dl if greater
down1:
add dl, 30h   ; Convert the remainder to ASCII
mov [rdi], dl   ; Store the ASCII character in the num array
dec rdi   ; Decrement the destination index
cmp ax, 0   ; Compare the quotient with 0
jne loop3   ; Jump to loop3 label if ax is not zero (repeat the loop)

scall 1, 1, msg, msgLen   ; Invoke the scall macro to write the message to the standard output
scall 1, 1, num, 5   ; Invoke the scall macro to write the hexadecimal number to the standard output

exit:
mov rax, 60   ; Set the system call number for exit
mov rdx, 0   ; Set the exit status to 0
syscall   ; Invoke the system call
