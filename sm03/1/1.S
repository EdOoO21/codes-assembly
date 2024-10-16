.intel_syntax noprefix
    .global main

    .text
main:
    push rbp
    mov rbp, rsp
read_first_string:
    call getchar
    cmp rax, 10
    je read_second_string
    cmp rax, 32
    je read_first_string
    cmp rax, 90
    lea r12, [arr_after_first_string + rip]
    jle high_to_low
    jmp arr_after_first_string

read_second_string:
    call getchar
    cmp rax, 10
    je checker
    cmp rax, 32
    je read_second_string
    cmp rax, 90
    lea r12, [arr_after_second_string + rip]
    jle high_to_low
    jmp arr_after_second_string

arr_after_first_string:
    lea r12, [rip + a]
    mov r13, [r12 + rax*8]
    add r13, 1
    mov [r12 + rax*8], r13
    jmp read_first_string

arr_after_second_string:
    lea r12, [rip + a]
    mov r13, [r12 + rax*8]
    sub r13, 1
    mov [r12 + rax*8], r13
    jmp read_second_string

checker: // sssss
    lea r12, [rip + a]
    mov r12, [r12 + r13*8]
    cmp r12, 0
    jnz no
    inc r13
    cmp r13, 128
    jne checker

yes:
    lea rdi, [rip + yeah]
    call puts
    jmp final
no:
    lea rdi, [rip + nah]
    call puts
    jmp final

final:

    mov rsp, rbp
    pop rbp
    xor eax, eax
    ret








high_to_low:
    cmp rax, 65
    jge extra
    jmp r12
extra:
    add rax, 32
    jmp r12


    .bss
a:
    .skip 128 * 8
    .text
yeah:
    .asciz "YES"
nah:
    .asciz "NO"


