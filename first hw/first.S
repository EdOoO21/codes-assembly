    .intel_syntax noprefix
    .global main
main:
    mov rdi, 42
    call writei64    // вывели результат
    call finish      // завершили программу