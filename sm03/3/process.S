    .intel_syntax noprefix
    .global process
process:
    mov rax, 4
    mov rsp, rbp
    pop rbp
    ret