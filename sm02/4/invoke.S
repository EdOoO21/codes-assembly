        .att_syntax     noprefix
        .text
        .align  16
        .global invoke
// rdi - rbx - arr
// rsi - esi - size
// rdx - edi - pivot
invoke:
        push    rbp
        mov     rsp, rbp
        push    rbx
        push    rdi

        mov     rdi, rbx
        mov     rdx, rdi
        call    partition
        mov     edx, eax

        pop     rcx
        cmp     rcx, rbx
        jnz     fail

        pop     rbx
        pop     rbp
        ret
fail:
        lea     msg(rip), rdi
        lea     stderr(rip), rsi
        call    fputs
        call    abort
        .section        .rodata
msg:    .asciz  "subroutine 'partition' messed up rbx\n"