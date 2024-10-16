extern void print_tb();
void bar();

void foo() {
    bar();

}

void bar() {
    return;
}

int main() {
    foo();
    foo();
    foo();
    foo();
    foo();
    bar();
    foo();
    foo();
    foo();
    foo();
    foo();
    bar();
    print_tb();
    return 0;
}
