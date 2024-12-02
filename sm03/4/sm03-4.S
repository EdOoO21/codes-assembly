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
metki:
    .quad foo
    .quad bar
    .quad main
    .quad print_tb

slova:
    .quad f_s
    .quad b_s
    .quad m_s
    .quad p_s

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
////////////////////////////
    lea rdi, [rip + p_s]
    call puts
///////////////////////////////
    mov rcx, 4
loop1:
    lea rdx, [rcx - 1]
    lea r8, [rip + metki]
    lea rdi, [rip + slova]
loop2:
    //////
    mov rsi, [r8]
    mov r9, [r8 + 8]
    cmp rsi, r9
    jbe no
    //////
    mov [r8], r9
    mov [r8 + 8], rsi
    //////
    mov rsi, [rdi]
    mov r9, [rdi + 8]
    mov [rdi], r9
    mov [rdi + 8], rsi
    //////
no:
    add r8, 8
    add rdi, 8
    dec rdx
    jnz loop2

    dec rcx
    cmp rcx, 1
    jne loop1
////////////////////////////////////
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////////////////////////////////
////////////////////////////////////

    lea r8, [rbp + 8]
loop:
    lea rsi, [rip + metki]
    lea rcx, [rip + slova]
    mov rdi, [r8]
///////////////////////////////////
    cmp rdi, [rsi + 8]
    jl first
    cmp rdi, [rsi + 16]
    jl second
    cmp rdi, [rsi + 24]
    jl third
//////////////////////////////////////////
    mov rdi, [rcx + 24]
    push r8
    push rcx
    call puts
    pop rcx
    pop r8
    add r8, 16

    lea r9, [rip + m_s]
    cmp r9, [rcx + 24]
    je end

    jmp loop
first:
    mov rdi, [rcx]
    push r8
    push rcx
    call puts
    pop rcx
    pop r8
    add r8, 16

    lea r9, [rip + m_s]
    cmp r9, [rcx]
    je end

    jmp loop
second:
    mov rdi, [rcx + 8]
    push r8
    push rcx
    call puts
    pop rcx
    pop r8
    add r8, 16

    lea r9, [rip + m_s]
    cmp r9, [rcx + 8]
    je end

    jmp loop
third:
    mov rdi, [rcx + 16]
    push r8
    push rcx
    call puts
    pop rcx
    pop r8
    add r8, 16

    lea r9, [rip + m_s]
    cmp r9, [rcx + 16]
    je end

    jmp loop
end:
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




