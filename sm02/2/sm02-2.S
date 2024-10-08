    .intel_syntax noprefix
    .global A, B, R, process
    .data
A: .int 0
B: .int 0
R: .int 0
    .text
process:
    mov edi, [rip + A]
    mov esi, [rip + B]
    xor edx, edx
loop:
    cmp esi, 0
    jz end
    mov ecx, esi
    and ecx, 1
    jnz loop1
    shl edi, 1
    shr esi, 1
    jmp loop
loop1:
    add edx, edi
    shl edi, 1
    shr esi, 1
    jmp loop
end:
    mov [rip + R], edx
    ret



