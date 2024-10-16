    .intel_syntax noprefix
    .global main
main:
    xor r12, r12
    xor r13, r13
    xor r14, r14
even:
    add r14, r12
loop:
    call readi64
    jc end
    mov r12, rax
    test r12, 1
    jz even
    add r13, r12
    jmp loop
end:
    mov rdi, r14
    call writei64
    mov rdi, r13
    call writei64
    call finish