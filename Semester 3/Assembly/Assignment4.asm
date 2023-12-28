section .data
msg1 db "Base Address: ", 10          ; Message string for base address
msg1len equ $-msg1                     ; Length of msg1

msg2 db "Offset: ", 10                 ; Message string for offset
msg2len equ $-msg2                     ; Length of msg2

msg3 db "Global Descriptor Table Register", 10  ; Message string for GDT register
msg3len equ $-msg3                     ; Length of msg3

msg4 db "Interrupt Descriptor Table Register", 10  ; Message string for IDT register
msg4len equ $-msg4                     ; Length of msg4

msg5 db "Task Register", 10            ; Message string for Task Register
msg5len equ $-msg5                     ; Length of msg5

msg6 db "Local Descriptor Table Register", 10   ; Message string for LDT register
msg6len equ $-msg6                     ; Length of msg6

msg7 db "Machine Status Word", 10      ; Message string for MSW register
msg7len equ $-msg7                     ; Length of msg7

newl db 0AH                            ; Newline character

%macro operate 4                        ; Macro for system calls
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .bss
gdtr resq 1                            ; Global Descriptor Table Register
gdtrlim resw 1                         ; GDT Limit

idtr resq 1                            ; Interrupt Descriptor Table Register
idtrlim resw 1                         ; IDT Limit

tr resw 1                              ; Task Register
ldtr resw 1                            ; Local Descriptor Table Register
msw resw 1                             ; Machine Status Word
temp64 resq 1                          ; Temporary storage for 64-bit values
temp16 resw 1                          ; Temporary storage for 16-bit values
asc resb 1                             ; Temporary storage for ASCII character

section .text
global _start
start:
operate 1,1,newl,1                     ; Print newline character
; Operation on msg3 with length msg3len
operate 1,1,msg3,msg3len

; Operation on msg1 with length msg1len
operate 1,1,msg1,msg1len

; Move the value of the global descriptor table register (gdtr) to the source index register (rsi)
mov rsi,gdtr

; Store the global descriptor table into the memory location pointed by rsi
sgdt[rsi]

; Move the value at the memory location pointed by rsi into the accumulator register (rax)
mov rax, [rsi]

; Call the display64 subroutine/function to display the hexadecimal representation of rax
call display64

; Output a newline character
operate 1,1,newl,1

; Operation on msg2 with length msg2len
operate 1,1,msg2,msg2len

; Move the value of the global descriptor table limit (gdtrlim) to rsi
mov rsi, gdtrlim

; Move the value at the memory location pointed by rsi into ax
mov ax,[rsi]

; Call the display16 subroutine/function to display the hexadecimal representation of ax
call display16

; Output a newline character
operate 1,1,newl,1

; Operation on msg4 with length msg4len
operate 1,1,msg4,msg4len

; Operation on msg1 with length msg1len
operate 1,1,msg1,msg1len

; Move the value of the interrupt descriptor table register (idtr) to rsi
mov rsi,idtr

; Store the interrupt descriptor table into the memory location pointed by rsi
sidt[rsi]

; Move the value at the memory location pointed by rsi into the accumulator register (rax)
mov rax, [rsi]

; Call the display64 subroutine/function to display the hexadecimal representation of rax
call display64

; Output a newline character
operate 1,1,newl,1

; Operation on msg2 with length msg2len
operate 1,1,msg2,msg2len

; Move the value of the global descriptor table limit (gdtrlim) to rsi
mov rsi, gdtrlim

; Move the value at the memory location pointed by rsi into ax
mov ax,[rsi]

; Call the display16 subroutine/function to display the hexadecimal representation of ax
call display16

; Output a newline character
operate 1,1,newl,1

; Operation on msg6 with length msg6len
operate 1,1,msg6,msg6len

; Output a newline character
operate 1,1,newl,1

; Operation on msg2 with length msg2len
operate 1,1,msg2,msg2len

; Move the value of the local descriptor table register (ldtr) to rsi
mov rsi, ldtr

; Move the value at the memory location pointed by rsi into ax
mov ax,[rsi]

; Call the display16 subroutine/function to display the hexadecimal representation of ax
call display16

; Output a newline character
operate 1,1,newl,1

; Operation on msg4 with length msg4len
operate 1,1,msg4,msg4len

; Output a newline character
operate 1,1,newl,1

; Operation on msg2 with length msg2len
operate 1,1,msg2,msg2len

; Move the value of the task register (tr) to rsi
mov rsi, tr

; Move the value at the memory location pointed by rsi into ax
mov ax,[rsi]

; Call the display16 subroutine/function to display the hexadecimal representation of ax
call display16

; Output a newline character
operate 1,1,newl,1

; Operation on msg4 with length msg4len
operate 1,1,msg4,msg4len

; Output a newline character
operate 1,1,newl,1

; Operation on msg2 with length msg2len
operate 1,1,msg2,msg2len

; Move the value of the machine status word register (msw) to rsi
mov rsi, msw

; Move the value at the memory location pointed by rsi into ax
mov ax,[rsi]

; Call the display16 subroutine/function to display the hexadecimal representation of ax
call display16

; Output a newline character
operate 1,1,newl,1

; Output a newline character 60 times with no operands (opcode 60)
operate 60,0,0,0

; Label for the display64 subroutine
display64:

; Move 16 to bp
mov bp,16

; Loop to display the hexadecimal representation of a 64-bit value
again1:
    ; Rotate the value in rax left by 4 bits
    rol rax,4

    ; Move the rotated value to temp64
    mov[temp64], rax

    ; Mask out the lower 4 bits
    and rax,0FH

    ; Compare the value with 9H
    cmp rax,09H

    ; Jump if below or equal (less than or equal to 9)
    jbe skip64

    ; Add 7H to the value if it's greater than 9
    add al, 07H

    ; Skip the addition
    skip64:

    ; Add 30H to convert to ASCII
    add al, 30H

    ; Store the ASCII value in asc
    mov [asc], al

    ; Output the ASCII value
    operate 1,1,asc,1

    ; Move the original value back to rax
    mov rax, [temp64]

    ; Decrement bp
    dec bp

    ; Jump if not zero to repeat the loop
    jnz again1

; Return from the subroutine
ret

; Label for the display16 subroutine
display16:

; Move 4 to bp
mov bp,4

; Loop to display the hexadecimal representation of a 16-bit value
again2:
    ; Rotate the value in ax left by 4 bits
    rol ax,4

    ; Move the rotated value to temp16
    mov[temp16],ax

    ; Mask out the lower 4 bits
    and ax, 0FH

    ; Compare the value with 9H
    cmp al, 09H

    ; Jump if below or equal (less than or equal to 9)
    jbe skip16

    ; Add 7H to the value if it's greater than 9
    add al, 07H

    ; Skip the addition
    skip16:

    ; Add 30H to convert to ASCII
    add al, 30H

    ; Store the ASCII value in asc
    mov [asc], al

    ; Output the ASCII value
    operate 1,1,asc,1

    ; Move the original value back to ax
    mov ax,[temp16]

    ; Decrement bp
    dec bp

    ; Jump if not zero to repeat the loop
    jnz again2

; Return from the subroutine
ret
