    .intel_syntax noprefix
    .global print_tb
    .extern puts
    .data
p_s:
    .asciz "print_tb"
f_s:
    .asciz "foo"
b_s:
    .asciz "bar"
m_s:
    .asciz "main"

    .text
print_tb:
    push rbp
    mov rbp, rsp
    push r8
    push r9
    push rdi
    push rsi
    push rcx
    push rdx

    lea rdi, [rip + p_s]
    call puts

    mov r9, 7

    lea r8, [rsp + r9*8]
    inc r9
    inc r9
loop:
    mov rdi, [r8]
    lea rsi, [rip + foo]
    lea rcx, [rip + bar]
    lea rdx, [rip + main]
loop1:
    cmp rdi, rsi
    je foos
    cmp rdi, rcx
    je bars
    cmp rdi, rdx
    je mains
    sub rdi, 2
    jmp loop1


foos:
    lea rdi, [rip + f_s]
    call puts
    lea r8, [rsp + r9*8]
    inc r9
    inc r9
    jmp loop
bars:
    lea rdi, [rip + b_s]
    call puts
    ///
    lea r8, [rsp + r9*8]
    inc r9
    inc r9
    ///
    jmp loop

mains:

    lea rdi, [rip + m_s]
    call puts

    pop rdx
    pop rcx
    pop rsi
    pop rdi
    pop r9
    pop r8
    mov rsp, rbp
    pop rbp
    xor rax, rax
    ret




