    .intel_syntax noprefix
    .text
    .global sort_by_abs
    .extern qsort
// rdi, rsi, rdx, rcx, r8, r9;
sort_by_abs:
    mov rdx, 2
    lea rcx, [rip + compare]
    jmp qsort

compare:
    movsx r8, word ptr [rdi]
    movsx r9, word ptr [rsi]

    cmp r8, 0
    jge next
    neg r8
next:
    cmp r9, 0
    jge next1
    neg r9
next1:
    cmp r8, r9
    jl l
    jg r
    xor rax, rax
    ret
l:
    mov rax, -1
    ret
r:
    mov rax, 1
    ret




