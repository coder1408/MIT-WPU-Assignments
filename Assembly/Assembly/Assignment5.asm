section .data
msg1 db "Error", 10         ; Error message
msgl1 equ $-msg1            ; Length of msg1
msg2 db "File copy successful", 10  ; Success message
msgl2 equ $-msg2            ; Length of msg2

%macro operate 4            ; Macro for system calls
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .bss
fname1 resb 15              ; Buffer for the first filename
fd1 resq 1                  ; File descriptor for the first file
fname2 resb 15              ; Buffer for the second filename
fd2 resq 1                  ; File descriptor for the second file
buff resb 512               ; Buffer for data transfer
bufflen resq 1              ; Buffer length

section .text
global _start
_start:
pop r13                      ; Pop the first argument (argc) from the stack
cmp r13, 3                   ; Check if argc is equal to 3
jne err                      ; Jump to err label if not equal

pop r13                      ; Pop the second argument (argv) from the stack
pop r13                      ; Pop the address of the filename from the stack
mov rsi, fname1             ; Set rsi to point to fname1

above:
mov al, [r13]               ; Load a byte from the filename
cmp al, 00                   ; Check if it's the end of the string
je next                      ; Jump to next label if end of the string
mov [rsi], al                ; Copy the byte to fname1
inc r13                      ; Move to the next byte in the filename
inc rsi                      ; Move to the next byte in fname1
jmp above                    ; Repeat the loop

next:
pop r13                      ; Pop the address of the second filename from the stack
mov rsi, fname2             ; Set rsi to point to fname2

above2:
mov al, [r13]               ; Load a byte from the second filename
cmp al, 00                   ; Check if it's the end of the string
je next2                     ; Jump to next2 label if end of the string
mov [rsi], al                ; Copy the byte to fname2
inc r13                      ; Move to the next byte in the second filename
inc rsi                      ; Move to the next byte in fname2
jmp above2                   ; Repeat the loop

next2:
operate 2, fname1, 000000q, 0777q  ; Open the first file
mov [fd1], rax               ; Store the file descriptor in fd1
operate 0, [fd1], buff, 512  ; Read from the first file
mov [fd1], rax               ; Store the result in fd1
operate 0, [fd1], buff, 512  ; Read from the first file again
mov [bufflen], rax           ; Store the result in bufflen
operate 85, fname2, 0777q,0  ; Open the second file (create if not exist)
mov [fd2], rax               ; Store the file descriptor in fd2
operate 1, [fd2], buff, [bufflen] ; Write to the second file
operate 3, [fd2],0,0         ; Close the second file
operate 3, [fd1],0,0         ; Close the first file
operate 1,1,msg2,msgl2       ; Print the success message
jmp end                      ; Jump to end label

err:
operate 1,1,msg1,msgl1       ; Print the error message

end:
operate 60,0,0,0             ; Exit the program
