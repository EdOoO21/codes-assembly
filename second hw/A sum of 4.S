    .intel_syntax noprefix
    .global main
main:
    call readi64
    mov r12, rax

    call readi64
    sal rax, 1
    sub r12, rax

    call readi64
    mov r13, rax
    sal rax, 4
    add rax, r13
    add r12, rax

    call readi64
    mov rdi, rax
    call writei64

    mov rdi, r12
    call writei64
    call finish