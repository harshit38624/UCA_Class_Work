#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t start, end;
    int n;
    scanf("%d", &n);
    srand(time(0));
    
    int arr[n];


    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    start = clock();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if(arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    end = clock();

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("%f", (double)(end - start) / CLOCKS_PER_SEC);

}