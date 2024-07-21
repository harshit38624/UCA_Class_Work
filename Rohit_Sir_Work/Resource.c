#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() {
        struct rusage r_start;
        getrusage(RUSAGE_SELF, &r_start);

        int* arr = (int* ) malloc (10000000 * sizeof(int));

        for (int i = 0; i < 10000000; i++) {
                arr[i] = i;
        }

        struct rusage r_end;
        getrusage(RUSAGE_SELF, &r_end);

        printf("%ld Kilobytes", r_end.ru_maxrss - r_start.ru_maxrss);
        free(arr);
}

