#include <stdio.h>

extern void print_tb();
void bar() {
    print_tb();
}
void foo() {

    bar();
}

int main() {
    foo();
    return 0;
}
