#include <stdio.h>
#include <stdlib.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))
#define LL long long

typedef struct BSearchResult {
    size_t low;
    size_t high;
    int result;
} BSearchResult;

BSearchResult
bsearch2(const void *key, const void *base, size_t nmemb, size_t size,
         int (*compar)(const void *p1, const void *p2, void *user),
         void *user) {
    BSearchResult ans = {0, 0, 0};
    size_t l = 0, r = nmemb, m;

    while (l < r) {
        m = l + (r - l) / 2;
        if (compar((char *)base + (m * size), key, user) < 0) {
            l = m + 1;
        } else if (compar((char *)base + (m * size), key, user) > 0) {
            r = m;
        } else {
            ans.result = 1;
            size_t saved = m;

            l = 0;
            r = m;
            while (l < r) {
                m = l + (r - l) / 2;
                if (compar((char *)base + (m * size), key, user) < 0) {
                    l = m + 1;
                } else if (compar((char *)base + (m * size), key, user) >= 0) {
                    r = m;
                }
            }
            if (compar((char *)base + (l * size), key, user) == 0) {
                ans.low = l;
            } else {
                ans.low = r;
            }

            l = saved;
            r = nmemb;
            while (l < r) {
                m = l + (r - l) / 2;
                if (compar((char *)base + (m * size), key, user) <= 0) {
                    l = m + 1;
                } else if (compar((char *)base + (m * size), key, user) > 0) {
                    r = m;
                }
            }

            if ((l < nmemb) &&
                (compar((char *)base + (l * size), key, user) > 0)) {
                ans.high = l;
            } else if ((r < nmemb) &&
                       (compar((char *)base + (r * size), key, user) > 0)) {
                ans.high = r;
            } else {
                ans.high = nmemb;
            }
            return ans;
        }
    }

    ans.low = l;
    ans.high = l;
    return ans;
}



int compare_ints(const void *p1, const void *p2, void *user) {
    (void)user; // Не используем user в данном случае
    int a = *(int *)p1;
    int b = *(int *)p2;
    return (a > b) - (a < b); // Возвращает отрицательное, 0 или положительное значение
}

int main(void) {
    int arr[] = {1,2,3,5};
    size_t nmemb = LEN(arr);
    int key = 5;

    BSearchResult result = bsearch2(&key, arr, nmemb, sizeof(int), compare_ints, NULL);


    printf("key = %d || low = %zu || high = %zu\n", result.result, result.low, result.high);


    return 0;
}

