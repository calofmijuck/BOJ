import java.util.*;
import java.io.*;

public class SelectionSort {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintStream ps = new PrintStream(new File("SSoutput.txt"));
        int[] arr = new int[sc.nextInt()];
        for(int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        // Check Time
        long start = System.currentTimeMillis();
        sort(arr);
        long end = System.currentTimeMillis();

        System.out.println("Sorted!");
        ps.println(Arrays.toString(arr));
        System.out.println(end - start + "ms");
    }

    public static void sort(int[] arr) {
        int tmp, cmp = 0;
        int minIndex;
        for(int i = 0; i < arr.length; i++) {
            minIndex = i;
            for(int j = i + 1; j < arr.length; j++) {
                cmp++;
                if(arr[minIndex] > arr[j]) {
                    minIndex = j;
                }
            }
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
        System.out.println("Number of Comparisons: " + cmp);
    }
}
