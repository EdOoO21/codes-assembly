    .intel_syntax noprefix
    .global gcd
gcd:
    push rbp
    mov rbp, rsp
    push rdi // n
    push rsi // m
    push rcx
    cmp rdi, 0
    jge next1
    neg rdi
next1:
    cmp rsi, 0
    jge next2
    neg rsi
next2:
    xor cl, cl
    xor rax, rax
go:
    // 1
    cmp rdi, 0
    je end_with_zero_rdi
    cmp rsi, 0
    je end_with_zero_rsi
    cmp rdi, rsi
    je end_equal

    // 2
    cmp rdi, 1
    je end_oneof_is_on
    cmp rsi, 1
    je end_oneof_is_on
    // 3
    test rdi, 1
    jz check_rsi
back:
    // 4
    test rdi, 1
    jz half_rdi

    // 5
    test rsi, 1
    jz half_rsi

    // 6
    cmp rdi, rsi
    jl half_dec_for_rsi // rdi < rsi

    sub rdi, rsi
    shr rdi, 1
    jmp go
// 6
half_dec_for_rsi:
    sub rsi, rdi
    shr rsi, 1
    jmp go
// 5
half_rsi:
    shr rsi, 1
    jmp go
// 4
half_rdi:
    shr rdi, 1
    jmp go
// 3
check_rsi:
    test rsi, 1
    jnz back
    inc cl
    shr rsi, 1
    shr rdi, 1
    jmp go


// 2  endsss
end_oneof_is_on:
    mov rsi, 1
    shl rsi, cl
    mov rax, rsi
    jmp end
// 1
end_with_zero_rdi:
    shl rsi, cl
    mov rax, rsi
    jmp end
end_with_zero_rsi:
    shl rdi, cl
    mov rax, rdi
    jmp end
end_equal:
    shl rdi, cl
    mov rax, rdi
    jmp end

end:

    pop rcx
    pop rsi
    pop rdi
    mov rsp, rbp
    pop rbp
    ret
