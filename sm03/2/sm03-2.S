    .intel_syntax noprefix
    .global ackermann
    .text
ackermann:
    push rbp
    mov rbp, rsp
    cmp rdi, 0
    jz first
    jmp second
first:
    inc rsi
    mov rax, rsi
    jmp end
second:
    cmp rsi, 0
    jnz third
    dec rdi
    mov rsi, 1
    call ackermann
    jmp end
third:
    push rdi
    push rsi

    dec rsi
    call ackermann

    pop rsi
    pop rdi
    mov rsi, rax
    dec rdi
    call ackermann
end:
    mov rsp, rbp
    pop rbp
    ret