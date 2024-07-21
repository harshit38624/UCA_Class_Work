#include <stdio.h>

int main() {
    int arr[] = {1,8,100,300,2,-1,7,6,4,5,2,70,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if(arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}