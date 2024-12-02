    .global gc_collect
gc_collect:
    push %rbp
    mov %rsp, %rbp
    sub $8, %rsp
    push %rbx
    push %r12
    push %r13
    push %r14
    push %r15

    mov %rsp, %rdi
    call gc_collect_impl

    leave
    ret
