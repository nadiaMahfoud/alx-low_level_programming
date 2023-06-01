section .data
    message db 'Hello, Holberton', 0

section .text
    extern printf
    global main

    ; Entry point of the program
main:
    ; Save the base pointer
    push rbp
    mov rbp, rsp

    ; Push the address of the format string onto the stack
    mov rdi, message
    xor eax, eax

    ; Call printf
    call printf

    ; Clean up the stack
    mov rsp, rbp
    pop rbp

    ; Exit the program
    xor eax, eax
    ret
