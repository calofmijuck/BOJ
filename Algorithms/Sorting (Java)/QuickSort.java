import java.util.*;
import java.io.*;

public class QuickSort {
    static int cmp = 0;
    static int[] arr;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintStream ps = new PrintStream(new File("QSoutput.txt"));
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
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j < high; j++) {
            cmp++;
            if(arr[j] < pivot) {
                i++;
                // swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
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
