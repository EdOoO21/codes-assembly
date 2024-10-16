|                      |       |
|----------------------|-------|
| **Time limit:**      | `1 s` |
| **Real time limit:** | `5 s` |
| **Memory limit:**    | `64M` |


### Problem sm04-2: asm/codegen/plt

В тестирующей программе имеется 6 подпрограмм func0, func1, ..., func5, адреса которых в памяти
неизвестны, и подпрограмма `void* resolve(int N)`, которая возвращает адрес подпрограммы funcN. К
сожалению, resolve работает довольно медленно, и нам хотелось бы избежать лишних вызовов resolve.

Определите в сдаваемом файле секцию .rwplt, доступную для записи и исполнения кода, следующим
образом:

`.section .rwplt, "axw"`

Определите в секции .rwplt 6 меток stub0, stub1, ..., stub5 таким образом, чтобы:

* при первом вызове call stubN сначала вызывалась функция resolve(N), а затем происходил переход в функцию funcN;
* при последующих вызовах call stubN сразу происходил переход в функцию funcN.

Указание: напишите в секции .text вспомогательную подпрограмму fix_stub, которая вызывает resolve и
записывает после метки stubN новый машинный код.

Секция .rwplt должна иметь размер не более 48 байт. Секции .data (и других writeable секций) в
сдаваемом файле быть не должно.

Гарантируется, что общий размер всех секций программы не превышает 2 ГБ.

Игнорируйте следующее предупреждение компоновщика:

`/usr/bin/ld: warning: program has a LOAD segment with RWX permissions`

Бонус: попробуйте обойтись 35 байтами в секции .rwplt.

    
    
    #include <stdio.h>
    
    static int func0(int a, int b) {
        return a + b;
    }
    static int func1(int a, int b) {
        return a - b;
    }
    static int func2(int a, int b) {
        return a * b;
    }
    static int func3(int a, int b) {
        return a / b;
    }
    static int func4(int a, int b) {
        return a % b;
    }
    static int func5(int a, int b) {
        return a & b;
    }
    int stub0(int a, int b);
    int stub1(int a, int b);
    int stub2(int a, int b);
    int stub3(int a, int b);
    int stub4(int a, int b);
    int stub5(int a, int b);
    
    typedef int (*func_t)(int, int);
    func_t funcs[] = {func0, func1, func2, func3, func4, func5};
    func_t stubs[] = {stub0, stub1, stub2, stub3, stub4, stub5};
    
    func_t resolve(unsigned a) {
        printf("resolve %u\n", a);
        return funcs[a];
    }
    
    int main() {
        int fn, a, b;
        while (scanf("%d %d %d", &fn, &a, &b) == 3) {
            int result = stubs[fn](a, b);
            printf("%d\n", result);
        }
        return 0;
    }
          

