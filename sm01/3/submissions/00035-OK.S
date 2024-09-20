    .intel_syntax noprefix
    .global main
main:
    call readi32
    mov r12d, eax
    mov edi, eax
    sub r12d, -1
    jle wrong_number
loop:
    mov r12d, edi
    call writei32
    mov edi, r12d
    dec edi
    jge loop
wrong_number:
    call finish