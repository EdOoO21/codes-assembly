        .intel_syntax noprefix
    .global main

    .bss
arr:
    .skip 128 * 8
    .text
yes_ans:
    .asciz "YES"
no_ans:
    .asciz "NO"

main:
    push rbp
    mov rbp, rsp
    push r12
    push r13
loop1:
    call getchar
    cmp rax, 32
    je loop1
    cmp rax, 10
    je loop
////
    cmp rax, 97
    lea r12, [back1 + rip]
    jge correct
back1:
////
    lea r12, [rip + arr]
    mov r13, [r12 + rax*8]
    inc r13
    mov [r12 + rax*8], r13
    jmp loop1
loop:
    call getchar
    cmp rax, 32
    je loop
    cmp rax, 10
    je end

///
    cmp rax, 97
    lea r12, [back + rip]
    jge correct
back:
////

    lea r12, [rip + arr]
    mov r13, [r12 + rax*8]
    dec r13
    mov [r12 + rax*8], r13
    jmp loop
end:
    xor r13, r13
loop2:
    lea r12, [rip + arr]
    mov r12, [r12 + r13*8]
    cmp r12, 0
    jnz no
    inc r13
    cmp r13, 128
    jne loop2
yes:
    lea rdi, [rip + yes_ans]
    call puts
    jmp final
no:
    lea rdi, [rip + no_ans]
    call puts
final:
    pop r13
    pop r12
    mov rsp, rbp
    pop rbp
    xor rax, rax
    ret


correct:
    cmp rax, 122
    jle next
    jmp r12
next:
    sub rax, 32
    jmp r12