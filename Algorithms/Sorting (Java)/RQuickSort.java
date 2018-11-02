import java.util.*;
import java.io.*;

public class RQuickSort {
    static int cmp = 0;
    static int[] arr;
    static Random rand = new Random();

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintStream ps = new PrintStream(new File("RQSoutput.txt"));
        int length = sc.nextInt();
        arr = new int[length];
        for(int i = 0; i < length; i++) {
            arr[i] = sc.nextInt();
        }
        long start = System.currentTimeMillis();
        sort(0, length - 1);
        long end = System.currentTimeMillis();

        System.out.println("Number of Comparisons: " + cmp);
        System.out.println("Sorted!");
        ps.println(Arrays.toString(arr));
        System.out.println(end - start + "ms");

    }

    static int partition(int low, int high) {
        int temp;
        // partition the Array
        int pivotIdx = rand.nextInt(high - low + 1) + low;
        int pivot = arr[pivotIdx]; // random element as pivot
        temp = arr[high];
        arr[high] = pivot;
        arr[pivotIdx] = temp;

        int i = low - 1;
        for(int j = low; j < high; j++) {
            cmp++;
            if(arr[j] < pivot) {
                i++;
                // swap
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = pivot;
        arr[high] = temp;
        return i + 1; // correct location of pivot in the array
    }

    static void sort(int low, int high) {
        if(low < high) {
            int pi = partition(low, high); // partitioning index

            sort(low, pi - 1);
            sort(pi + 1, high);
        }
    }
}
