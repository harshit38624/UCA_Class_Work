#include <stdio.h>

int main() {
    int arr[] = {1,8,100,300,2,-1,7,6,4,5,2,70,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);
    for (int i = 0; i < n - 1; i++) {
        int sorted = 1;
        for (int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 0;
            }
        }
        if(sorted == 1) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}