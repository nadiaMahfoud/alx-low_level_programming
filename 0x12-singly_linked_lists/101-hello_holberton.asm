section .data
    hello db "Hello, Holberton\n", 0
    format db "%s", 0

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    sub rsp, 8 ; Allocate space for two 64-bit arguments on the stack

    mov rdi, format ; Set the format string
    mov rsi, hello ; Set the address of the hello string

    xor eax, eax ; Clear the EAX register
    call printf ; Call the printf function

    add rsp, 8 ; Restore the stack pointer

    mov eax, 0 ; Set the return value to 0
    leave
    ret

