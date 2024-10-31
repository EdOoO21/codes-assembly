    .intel_syntax noprefix
    .global main
    .text
main:
    mov r15, 1 // конец массива stack
    mov rbx, 1 // версии
    lea r13, [rip + indexes]
    mov dword ptr [r13], 0
    xor rbp, rbp

go:
    call readi32
    jc end
    cmp eax, 0
    je pussh


    // pop
    call readi32
    mov ebp, eax

    lea r13, [rip + indexes]
    mov r12d, [r13 + rbp * 4]
    cmp r12d, -1
    je empty
    cmp r12d, 0
    je empty


    lea r13, [rip + stack]
    mov edi, [r13 + r12 * 8]
    call writei32


    mov r12d, [r13 + r12 * 8 + 4]
    lea r13, [rip + indexes]
    mov [r13 + rbx * 4], r12d

    inc rbx
    jmp go
pussh:
    call readi32
    mov ebp, eax
    call readi32
    mov r12d, eax

    lea r13, [rip + indexes]
    mov r14d, [r13 + rbp * 4]

    mov [r13 + rbx * 4], r15d


    lea r13, [rip + stack]
    mov [r13 + r15 * 8], r12d
    mov [r13 + r15 * 8 + 4], r14d


    inc r15
    inc rbx

    jmp go

empty:
    mov edi, -1
    call writei32
    jmp go

end:
    call finish

    .data
indexes:
    .skip 1010 * 4, -1
stack:
    .skip 1010 * 4 * 2, -1