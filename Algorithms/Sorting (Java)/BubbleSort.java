import java.util.*;
import java.io.*;

public class BubbleSort {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintStream ps = new PrintStream(new File("BSoutput.txt"));
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
        for(int i = 0; i < arr.length - 1; i++) {
            for(int j = 0; j < arr.length - i - 1; j++) {
                if(arr[j] > arr[j + 1]) {
                    tmp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = tmp;
                }
                cmp++;
            }
        }
        System.out.println("Number of Comparisons: " + cmp);
    }
}
