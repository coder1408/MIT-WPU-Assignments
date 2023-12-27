section .data
msg db "Sorted Array is: ", 10   ; Define a message string terminated by newline character (10)
msglen equ $-msg   ; Calculate the length of the message string
arr db 04h, 0Ch, 78h, 0E3h, 14h   ; Define an array with hexadecimal values

%macro operate 4   ; Define a macro named operate with 4 parameters
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .bss
Result resb 15   ; Reserve space for a byte (8-bit) array named Result with a size of 15 bytes

section .text
global _start
_start:

mov bl, 5   ; Set the outer loop counter to 5
loop_outer: 
mov cl, 4   ; Set the inner loop counter to 4
mov rsi, arr   ; Load the address of arr into the source index register (rsi)

up: 
mov al, byte[rsi]   ; Load the byte at the address in rsi into the al register
cmp al, byte[rsi+1]   ; Compare al with the next byte in the array
jbe only_inc   ; Jump to only_inc label if less than or equal (not greater)
xchg al, byte[rsi+1]   ; Exchange the values if al is greater
mov byte[rsi], al   ; Store the new value back in the array
only_inc: 
inc rsi   ; Increment the source index register
dec cl   ; Decrement the inner loop counter
jnz up   ; Jump to up label if cl is not zero (repeat the loop)

dec bl   ; Decrement the outer loop counter
jnz loop_outer   ; Jump to loop_outer label if bl is not zero (repeat the loop)

operate 1, 1, msg, msglen   ; Invoke the operate macro to write the message to the standard output

mov rdi, arr   ; Load the address of arr into the destination index register (rdi)
mov rsi, Result   ; Load the address of Result into the source index register (rsi)
mov dl, 5   ; Set the loop counter to 5

disp_loop: 
mov cl, 2   ; Set the inner loop counter to 2
mov al, [rdi]   ; Load a byte from arr into the al register

againx: 
rol al, 4   ; Rotate the bits in al left by 4 positions
mov bl, al   ; Copy the rotated value to bl
and al, 0FH   ; Mask the lower 4 bits of al
cmp al, 09H   ; Compare the masked value with 9
jbe downx   ; Jump to downx label if less than or equal to 9
add al, 07H   ; Add 7 to al if greater than 9
downx: 
add al, 30H   ; Convert the value in al to ASCII
mov byte[rsi], al   ; Store the ASCII character in Result
mov al, bl   ; Restore the original value from bl to al
inc rsi   ; Increment the source index register
dec cl   ; Decrement the inner loop counter
jnz againx   ; Jump to againx label if cl is not zero (repeat the loop)

mov byte[rsi], 0AH   ; Add a newline character to Result
inc rsi   ; Increment the source index register
inc rdi   ; Increment the destination index register
dec dl   ; Decrement the outer loop counter
jnz disp_loop   ; Jump to disp_loop label if dl is not zero (repeat the loop)

operate 1, 1, Result, 15   ; Invoke the operate macro to write the sorted array to the standard output
operate 60, 0, 0, 0   ; Invoke the operate macro to exit the program
