#include <sys/syscall.h>
    .intel_syntax noprefix
    .global _start
_start:
    pop rdi
    lea rsi, [rsp]
    add rsp, 8
    lea rdx, [rsp + rdi * 8]
    sub rsp, 8

    call main

    mov rdi, rax
    mov eax, SYS_exit
    syscall



