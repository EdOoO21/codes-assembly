    .intel_syntax noprefix
    .global main
main:
    xor r15, r15
    call readi64
    mov r12, rax
loop:
    test r12, 1
    jnz plus
    cmp r12, 0
    jz end
go:
    shr r12, 1
    jmp loop
plus:
    inc r15
    jmp go
end:
    mov rdi, r15
    call writei64
    call finish

