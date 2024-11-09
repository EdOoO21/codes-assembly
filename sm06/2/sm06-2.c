#include <stdio.h>
#include <stdlib.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))
#define LL long long
#define A 1103515245
#define C 12345
#define MOD 2147483648U

typedef struct RandomGenerator RandomGenerator;

typedef struct RandomOperations {
    unsigned (*next)(RandomGenerator *);
    void (*destroy)(RandomGenerator *);
} RandomOperations;

struct RandomGenerator {
    unsigned now;
    RandomOperations *ops;
};

static void destroys(RandomGenerator *gen) {
    free(gen);
}

static unsigned nexts(RandomGenerator *gen) {
    gen->now = ((gen->now * A) + C) % MOD;
    return gen->now;
}

static const RandomOperations GLOBAL = {nexts, destroys};

RandomGenerator *random_create(int seed) {
    RandomGenerator *gen = (RandomGenerator *)calloc(1, sizeof(*gen));
    if (gen != NULL) {
        gen->now = seed;
        gen->ops = (RandomOperations *)&GLOBAL;
    }
    return gen;
}

int main() {
    RandomGenerator *rr = random_create(1234);
    for (int j = 0; j < 10; ++j) {
        printf("%d\n", rr->ops->next(rr));
    }
    rr->ops->destroy(rr);
    return 0;
}