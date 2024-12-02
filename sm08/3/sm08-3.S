    .intel_syntax noprefix
    .global okay
okay:
    push rbp
    mov rbp, rsp
    mulsd xmm0, xmm0
    mulsd xmm0, xmm0

    mulsd xmm1, xmm1
    mulsd xmm1, xmm1

    addsd xmm0, xmm1

    sqrtsd xmm0, xmm0

    movsd [rdi], xmm0

    mov rsp, rbp
    pop rbp
    xor rax, rax
    ret