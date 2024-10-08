    .intel_syntax noprefix
    .global partition
partition:
    xor r8, r8
    xor r9, r9
loop:
    cmp r9, rsi
    jz end

    cmp [rbx + r9*2], di
    jge to_right

    mov cx, [rbx + r9*2]
    mov dx,  [rbx + r8*2]
    mov  [rbx + r9*2], dx
    mov [rbx + r8*2], cx
    inc r9
    inc r8
    jmp loop
to_right:
    inc r9
    jmp loop
end:
    mov rdx, r8
    ret




