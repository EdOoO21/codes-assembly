    .intel_syntax noprefix
    .global main
    .extern megacall
main:
    call readi32
    mov r12d, eax
    call readi32
    mov r13d, eax
    call readi32
    mov r14d, eax

    mov edi, r12d
    mov esi, r13d
    mov edx, r14d

    mov cl, 49
    mov r8b, 50
    mov r9b, 48

    mov r12, -3
    push r12
    mov r12,-2
    push r12
    mov r12, -1
    push r12

    call megacall

    movsx edi, ax
    call writei32

    pop r12
    pop r13
    call finish

