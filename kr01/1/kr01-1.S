    .intel_syntax noprefix
    .global process, A, B, R
    .data
A:  .int
B:  .int
R:  .int

    .text
process:
    lea r9, [rip + A]
    mov [r9], edi
    mov r9d, edi

    lea r8, [rip + B]
    mov [r8], esi
    mov r8d, esi

    sar r8d, 3



    add r9d, edi
    add r9d, edi
    add r9d, edi
    add r9d, edi


    mov esi, r9d
    sub esi, r8d
    jo error
    lea r9, [rip + R]
    mov [r9], esi

    xor eax, eax
    ret
error:
    xor eax, eax
    ret



