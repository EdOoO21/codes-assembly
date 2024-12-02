    .intel_syntax noprefix
    .global okay
okay:
    push rbp
    mov rbp, rsp

    movss [rbp - 4], xmm0
    movss [rbp - 8], xmm1
    movss [rbp - 12], xmm2


    fld dword ptr [rbp - 4]
    fld dword ptr [rbp - 8]

    fcomi st(0), st(1)
    ja sin
    fstp dword ptr [rbp - 8]
    fstp dword ptr [rbp - 4]

    fld dword ptr [rbp - 12]
    fld dword ptr [rbp - 4]
    fprem

    fstp dword ptr [rbp - 4]
    fstp dword ptr [rbp - 12]

    fld dword ptr [rbp - 8]
    fld dword ptr [rbp - 4]

    fyl2x
    fstp dword ptr [rbp - 4]
    movss xmm0, dword ptr [rbp - 4]
    jmp end
sin:
    fadd dword ptr [rbp - 12]
    fsin
    fstp dword ptr [rbp - 16]
    movss xmm0, dword ptr [rbp - 16]
end:
    mov rsp, rbp
    pop rbp
    ret