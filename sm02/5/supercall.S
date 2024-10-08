    .intel_syntax noprefix
    .global supercall
supercall:
    push rbx

    mov rax, rdi
    mov rbx, rdx
    mov rdi, rcx
    mov rcx, r8
    call supersum

    pop rbx

    ret