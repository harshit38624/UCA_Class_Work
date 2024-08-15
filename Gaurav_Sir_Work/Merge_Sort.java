class Merge_Sort {
    static void merge(int[] arr) {
        if(arr.length < 2) {
            return;
        }
        int mid = arr.length / 2;
        int[] left = new int[mid];
        int[] right = new int[arr.length - mid];

        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }

        for (int i = mid ; i < arr.length; i++) {
            right[i - mid] = arr[i];
        }

        merge(left);
        merge(right);

        mergeSort(arr, left, right);
    }

    static void mergeSort(int[] arr, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;

        while (i < left.length && j < right.length) {
            if(left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < left.length) {
            arr[k++] = left[i++];
        }

        while (j < right.length) {
            arr[k++] = right[j++];
        }

    }
    public static void main(String[] args) {
        int[] arr = {3,2,1,3,6,4,5,8,12,1000000,345,2332,23,23,54,321,34,56};
        merge(arr);
        for (var i : arr) {
            System.out.print(i + " ");
        }
    }
}