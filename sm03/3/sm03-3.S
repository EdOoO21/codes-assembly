    .intel_syntax noprefix
    .global main
    .extern process
    .data
code:
    .asciz "%d\n"
    .text
main:
    push rbp
    mov rbp, rsp

    lea rax, [rip + after]
    push rax
    push rbp
    mov rbp, rsp
    jmp process
after:
    lea rdi, [rip + code]
    mov rsi, rax
    call printf

    mov rsp, rbp
    pop rbp
    xor rax, rax
    ret
