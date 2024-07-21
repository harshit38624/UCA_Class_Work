#include <stdio.h>

int main() {
    int arr[] = {1,8,100,300,2,-1,7,6,4,5,2,70,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while(j>=0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}