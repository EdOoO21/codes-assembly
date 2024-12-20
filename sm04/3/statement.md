|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem sm04-3: asm/hacks/rop

Return Oriented Programming (ROP) - это техника эксплуатации уязвимостей в ПО, используя которую,
злоумышленник добивается исполнения необходимого ему кода.

Основная идея техники заключается в том, что злоумышленник находит необходимые ему инструкции среди
уже присутствующего кода, и меняет ход программы нужным ему образом, изменяя стек вызовов (либо
напрямую, либо путём атаки на переполнение буфера, либо другими способами). Комбинируя таким образом
нужные ему участки кода, злоумышленник добивается нужного ему поведения программы.

Разберём атаку на простейшем примере. Дано: в программе присутствует функция `send_nukes`, которую
мы (как злоумышленник) хотим выполнить; основной код будет вызывать написанную нами функцию
`solution`, но нам нельзя пользоваться инструкциями `call`, `jmp` и прочими. Вспомним, что
происходит, когда мы завершаем свою функцию инструкцией `ret`: со стека берётся адрес возврата, и
дальше следует исполнение инструкций по этому адресу. Поэтому простейшая ROP-атака, при условии, что
программа выполняет наш код, выглядит следующим образом:

    
    
        .global solution
    solution:
        push    $send_nukes
        ret
            

Напишите подпрограмму rop, соответствующую сигнатуре `void rop(void)`, с помощью которой добейтесь
того, чтобы в процессе работы программы на стандартный поток вывода была напечатана строка `Hello,
world!` (с переводом строки на конце). Иными словами должна сфоримровать правильный стек с помощью
инсутркций lea и push и запустить rop исполнение.

Написанная функция (кроме меток и директив .global) может содержать только инструкции `push`, `lea`
и РОВНО ОДНУ инструкцию `ret`.

Написанная вами функция не должна содержать инструкций вызова (`call`) или инструкций перехода,
условного или безусловного, `mov` и прочие

Итоговый исполняемый файл будет компилироваться следующей командой: `gcc main.c functions.S
solution.S`, где `solution.S` \- это сдаваемый вами файл.

main.c:

    
    
    void rop(void);
    int main() {
        rop();
    }

functions.S:

    
    
        .intel_syntax noprefix
        .text
        .global f1
    f1:
        lea  rax, [rip + str0]
        push rax
        push rax
        pop  rdi
        xor  rax, rax
        call printf
        pop  rdi
        ret
    
        .global str0
        .global str1
        .global str2
    str0:
        .asciz "Fail\n"
    str1:
        .asciz "Hello, "
    str2:
        .asciz "world!\n"
            

P.S. не забывайте, что asm компилируется в байткод, и каждая инструкция кодируется всегда одинаковым
соответствующим ей числом байт.

