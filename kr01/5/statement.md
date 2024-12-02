|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem kr01-5: asm/hacks/ccg

Дана подпрограмма на языке ассемблера архитектуры x86_64:

    
    
    func:
        mov    rsi, [8 + rsp]
        mov    rax, [16 + rsp]
        lea    rax, [rsi + 8 * rax]
        mov    rsi, [rax]
        add    rax, [8 + rsi]
        add    rax, [24 + rsp]
        ret
    

Напишите эту подпрограмму на языке Си.

