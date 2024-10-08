    .intel_syntax noprefix
    .global main
main:
    xor r12, r12
set:
    call readi64
    jc get
    inc r12
    push rax
    jmp set
get:
    cmp r12, 0
    jz end
    pop rdi
    call writei64
    dec r12
    jnz get
end:
    call finish