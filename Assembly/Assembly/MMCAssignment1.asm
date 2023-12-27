section .data
Num_Array db 11h,12h,13h,14h,15h   ; Define an array with hexadecimal values 11h, 12h, 13h, 14h, 15h

msg db "Result of array addition is: ", 10   ; Define a message string terminated by newline character (10)
msglen equ $-msg   ; Calculate the length of the message string

section .bss
Result resw 1   ; Reserve space for a word (16-bit) variable named Result
temp resw 1     ; Reserve space for a word variable named temp

%macro rw 4   ; Define a macro named rw with 4 parameters
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .text
global _start
_start:

mov rsi, Num_Array   ; Load the address of Num_Array into the source index register (rsi)
mov ax, 00h          ; Initialize ax register to 0
mov cx, 5            ; Set the loop counter cx to 5

up2: 
mov bl, byte[rsi]    ; Load the byte at the address in rsi into the bl register
add ax, bx           ; Add the value in bl to ax
jnc skip             ; Jump to skip label if no carry flag is set
inc ah               ; Increment the high byte of ax if carry flag is set
skip: 
inc rsi              ; Increment the source index register
dec cx              ; Decrement the loop counter
jnz up2             ; Jump to up2 label if cx is not zero (repeat the loop)

mov word[Result], ax   ; Store the result in the Result variable

mov ax, word[Result]   ; Load the result back into the ax register
mov bp, 4              ; Set the loop counter to 4

up: 
rol ax, 4              ; Rotate the bits in ax left by 4 positions
mov bx, ax             ; Copy the rotated value to bx
and ax, 0Fh            ; Mask the lower 4 bits of ax
cmp al, 09h            ; Compare the masked value with 9
jbe down               ; Jump to down if less than or equal to 9
add al, 07h            ; Add 7 to al if greater than 9
down: 
add al, 30h            ; Convert the value in al to ASCII
mov byte[temp], al     ; Store the ASCII character in temp variable
rw 1, 1, temp, 1       ; Invoke the rw macro to write the ASCII character to the standard output
mov ax, bx             ; Restore the original value from bx to ax
dec bp                 ; Decrement the loop counter
jnz up                 ; Jump to up label if bp is not zero (repeat the loop)

rw 60, 0, 0, 0         ; Invoke the rw macro to exit the program
