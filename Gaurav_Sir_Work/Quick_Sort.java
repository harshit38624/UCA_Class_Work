import java.util.*;

class Quick_Sort {
    static void Qsort(int[] arr, int low, int high) {
        if(low < high) {
            int index = partition(arr, low , high);

            Qsort(arr, low, index - 1);
            Qsort(arr, index + 1, high);
        }
    }

    static int partition(int[] arr, int low, int high) {

        Random rand = new Random();
        int pivot = low + rand.nextInt(high - low + 1);

        swap(arr, pivot, high);

        int key = arr[high];

        int i = low - 1;
        for (int j = low; j < high; j++) {
            if(arr[j] < key) {
                i++;
                swap(arr, j, i);
            }
        }

        swap(arr, i + 1, high);
        return i + 1;

    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static void main(String[] args) {
        Random rand = new Random();
        int[] arr = new int[100];
        for (int i = 0; i < 100; i++) {
            arr[i] = rand.nextInt(1000);
        }
        Qsort(arr, 0, 99);

        for (var i : arr) {
            System.out.print(i + " ");
        }
    }    
}
