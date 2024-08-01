#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main() {
    struct timeval t_first;
    gettimeofday(&t_first, NULL);

    long long before = t_first.tv_sec * 1000LL + t_first.tv_usec/1000;

    long long int sum = 0;

    for (int i = 1; i < 1000000000; i++) sum += i;

    struct timeval t_last;
    gettimeofday(&t_last, NULL);

    long long after = t_last.tv_sec * 1000LL + t_last.tv_usec/1000;

    printf("%lld", after - before);
}