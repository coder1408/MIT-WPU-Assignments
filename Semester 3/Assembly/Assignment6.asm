%macro operate 4   ; Macro for system calls
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
m1 db "Enter String 1", 10       ; Message: Enter String 1
ml1 equ $-m1                     ; Length of m1

m2 db "Enter String 2", 10       ; Message: Enter String 2
ml2 equ $-m2                     ; Length of m2

m3 db "Concatenated String is: ", 10  ; Message: Concatenated String is:
ml3 equ $-m3                     ; Length of m3

m4 db "No. of spaces", 10        ; Message: No. of spaces
ml4 equ $-m4                     ; Length of m4

m5 db "No. of words", 10         ; Message: No. of words
ml5 equ $-m5                     ; Length of m5

section .bss
string1 resb 25                  ; Buffer for input string 1
string2 resb 25                  ; Buffer for input string 2
string3 resb 50                  ; Buffer for concatenated string
length1 resb 25                  ; Length of string 1
length12 resb 25                 ; Temporary storage for length of string 1 and 2
length2 resb 25                  ; Length of string 2
word1 resb 1                     ; Word count
space1 resb 1                    ; Space count

section .text
global _start
_start:

operate 1, 1, m1, ml1            ; Print "Enter String 1" message
operate 0, 0, string1, 25         ; Read input string 1
dec rax
mov[length1], rax                ; Store the length of string 1
mov[length12], rax

operate 1,1,m2,ml2               ; Print "Enter String 2" message
operate 0,0,string2,25           ; Read input string 2
dec rax
mov[length2], rax                ; Store the length of string 2
mov[length12], rax

call concatenate                ; Call concatenate subroutine
call words_spaces              ; Call words_spaces subroutine

concatenate:
mov rsi, string1              ; Set rsi to point to string1
mov rdi, string3              ; Set rdi to point to string3
copy1:
mov al, [rsi]                 ; Load a byte from string1
mov [rdi], al                 ; Copy the byte to string3
inc rsi                       ; Move to the next character in string1
inc rdi                       ; Move to the next character in string3
dec byte[length1]             ; Decrement the length of string1
jnz copy1                      ; Repeat until length1 is not zero

mov rsi, string2              ; Set rsi to point to string2
copy2:
mov al, [rsi]                 ; Load a byte from string2
mov [rdi], al                 ; Copy the byte to string3
inc rsi                       ; Move to the next character in string2
inc rdi                       ; Move to the next character in string3
dec byte[length2]             ; Decrement the length of string2
jnz copy2                      ; Repeat until length2 is not zero

operate 1,1,m3,ml3            ; Print "Concatenated String is: " message
operate 1,1,string3,50         ; Print the concatenated string
ret

words_spaces:
  mov rsi, string1            ; Set rsi to point to string1
  mov bl, 00                  ; Clear bl (word count)

up:
  mov al, [rsi]               ; Load a byte from string1
  cmp al, 20H                 ; Compare with space character
  jne nspace                  ; Jump to nspace if not a space
  inc bl                      ; Increment word count
nspace:
  inc rsi                     ; Move to the next character in string1
  dec byte[length12]          ; Decrement the length of string1
  jnz up                      ; Repeat until length12 is not zero

operate 1,1,m5,ml5            ; Print "No. of words" message

; Convert word count to ASCII
  add bl, '0'                 ; Convert word count to ASCII
  mov [space1], bl            ; Store the word count
  operate 1,1,space1,1         ; Print the word count as ASCII

operate 1,1,m4,ml4            ; Print "No. of spaces" message
  movzx eax, bl               ; Zero extend bl to eax
  operate 0, 1, eax, 1         ; Print the word count (as an integer)

  mov [word1], bl              ; Store the word count
  operate 1,1,word1,1          ; Print the word count

ret
