    .intel_syntax noprefix
    .global main
main:
    mov r8d, 12
    mov edi, r8d
    call writei32
    jmp check
    call getchar
    mov rdi,rax
    call writei64
    call finish

check:
    mov r12, 52
    jmp main