#include <cstdio>
#include <iostream>
extern "C"
unsigned long long ackermann(unsigned long long m, unsigned long long n);

unsigned long long ackermann1(unsigned long long m, unsigned long long n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermann1(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return ackermann1(m - 1, ackermann1(m, n - 1));
    }
    return 0; // Этот случай никогда не будет достигнут
}

int main() {
    bool ok = true;
    for (unsigned long long i = 0; i < 100; ++i) {
        for (unsigned long long j = 0; j < 100; ++j) {
            if (-1 != ackermann(i,j)) {
                std::cout << "ok" << " " << i << " " << j << std::endl;
            } else {
                std::cout << "FAIL" << " " << i << " " << j << "============================================" << std::endl;
                ok = false;
                break;
            }
        }
        if (!ok) {
            break;
        }
    }
}