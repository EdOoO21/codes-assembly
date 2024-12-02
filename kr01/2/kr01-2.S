    .intel_syntax noprefix
    .global count
    .text
count:
    xor rsi, rsi
    xor rdx, rdx
loop:
    mov al, byte ptr [rdi]
    sub al, 0
    jz end

    inc rdx

    cmp al, '0'
    jge mbnumb
back:
    cmp al, 'a'
    jge mbslet

    cmp al, 'A'
    jge mbblet

    inc rdi
    jmp loop
mbblet:
    cmp al, 'Z'
    jle corr
    jmp loop
mbslet:
    cmp al, 'z'
    jle corr
    jmp loop
mbnumb:
    cmp al, '9'
    jle corr
    jmp back
corr:
    inc rsi
    inc rdi
    jmp loop
end:
    sub rdx, rsi
    mov rax, rdx
    ret

