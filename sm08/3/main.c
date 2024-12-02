#include <stdio.h>
#include <math.h>
extern void okay(double x, double y, double *r);

int main() {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            double x = -1;
            double *r = &x;
            okay((double ) i, (double ) j, r);
            if (*r != ((sqrt(((j *j*j*j) + (i *i*i*i)))))) {
                printf("хуйня случилась на %d %d ||| %f != %f\n", i, j, *r, ( (sqrt(((j *j*j*j) + (i *i*i*i)))) ));
                break;
            }
        }
    }
}