import java.util.*;
import java.io.*;

public class MergeSort {
    static int cmp = 0;
    static int[] arr;
    static int[] tmp1;
    static int[] tmp2;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintStream ps = new PrintStream(new File("MSoutput.txt"));
        int length = sc.nextInt();
        arr = new int[length + 1];
        tmp1 = new int[length + 1];
        tmp2 = new int[length + 1];
        for(int i = 1; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        // Check Time
        long start = System.currentTimeMillis();
        sort(1, length);
        long end = System.currentTimeMillis();

        System.out.println("Number of Comparisons: " + cmp);
        System.out.println("Sorted!");
        ps.println(Arrays.toString(arr));
        System.out.println(end - start + "ms");
    }

    public static void sort(int p, int r) {
        if(p < r) {
            int q = (int) Math.ceil((p + r) / 2);
            sort(p, q);
            sort(q + 1, r);
            merge(p, q, r);
        }
    }

    public static void merge(int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;
        for(int i = 1; i <= n1; i++) {
            tmp1[i] = arr[p + i - 1];
        }
        for(int j = 1; j <= n2; j++) {
            tmp2[j] = arr[q + j];
        }
        tmp1[n1 + 1] = Integer.MAX_VALUE;
        tmp2[n2 + 1] = Integer.MAX_VALUE;
        int i = 1, j = 1;
        for(int k = p; k <= r; k++) {
            cmp++;
            if(tmp1[i] <= tmp2[j]) {
                arr[k] = tmp1[i];
                i++;
            } else {
                arr[k] = tmp2[j];
                j++;
            }
        }
    }
}
