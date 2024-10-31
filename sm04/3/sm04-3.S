    .intel_syntax noprefix
    .global rop
rop:
    pop rbp
    push rbp
    push rbp

    lea r9, [rip + f1]
    lea r9, [r9 + 10]

    push r9
///////////////////
    lea r9, [rip + f1]
    lea r9, [r9 + 9]
    lea r8 , [r9 + 25]

    push r8
///////////////////
    lea r8 , [r9 + 17]

    push r8
///////////////////

    push r9


    ret