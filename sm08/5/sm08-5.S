    .intel_syntax noprefix
    .global product
product:
    push rbp
    mov rbp, rsp
    xorpd xmm0, xmm0
    xor r8, r8
loop:
    cmp rdi, 4
    jl left

    movups xmm1, [rsi]
    movups xmm2, [rdx]
    mulps xmm1, xmm2

    hsubps xmm1, xmm1
    haddps xmm1, xmm1
    addss xmm0, xmm1

    add rsi, 16
    add rdx, 16
    sub rdi, 4
    add r8, 4
    jmp loop
left:
    cmp rdi, 0
    je end

    movss xmm1, [rsi]
    movss xmm2, [rdx]
    mulss xmm1, xmm2

    test r8, 1
    jnz nechet

    addss xmm0, xmm1
    inc r8
    dec rdi
    add rsi, 4
    add rdx, 4
    jmp left

nechet:
    subss xmm0, xmm1
    inc r8
    dec rdi
    add rsi, 4
    add rdx, 4
    jmp left
end:
    movss [rcx], xmm0
    mov rsp, rbp
    pop rbp
    ret