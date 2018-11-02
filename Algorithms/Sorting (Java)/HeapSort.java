import java.util.*;
import java.io.*;

public class HeapSort {
    static int cmp = 0;
    static int[] arr;
    static int size;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintStream ps = new PrintStream(new File("HSoutput.txt"));
        size = sc.nextInt();
        arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        long start = System.currentTimeMillis();
        sort();
        long end = System.currentTimeMillis();

        System.out.println("Number of Comparisons: " + cmp);
        System.out.println("Sorted!");
        ps.println(Arrays.toString(arr));
        System.out.println(end - start + "ms");
    }

    static void sort() {
        buildMaxHeap();
        int temp, n = arr.length - 1;
        for(int i = 0; i < n; ++i) {
            temp = arr[n - i];
            arr[n - i] = arr[0];
            arr[0] = temp;
            size--;
            maxHeapify(0);
        }
    }

    static void buildMaxHeap() {
        for(int i = arr.length / 2; i >= 0; --i) {
            maxHeapify(i);
        }
    }

    static void maxHeapify(int i) {
        int left = 2 * i + 1, right = 2 * i + 2;
        int temp;
        if(left < size)  { // left child exists
            if(right < size && arr[left] < arr[right]) { // right child exists and right child is greater
                ++cmp;
                left = right; // larger child
            }
            if(arr[i] < arr[left]) {
                ++cmp;
                temp = arr[i];
                arr[i] = arr[left];
                arr[left] = temp;
                maxHeapify(left);
            }
        }
    }
}
