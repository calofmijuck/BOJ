import java.util.*;
import java.io.*;

public class RadixSort {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("input.txt"));
        PrintStream ps = new PrintStream(new File("RSoutput.txt"));
        int length = sc.nextInt();
        int[] arr = new int[length];
        for(int i = 0; i < length; i++) {
            arr[i] = sc.nextInt();
        }

        long start = System.currentTimeMillis();
        radixSort(arr);
        long end = System.currentTimeMillis();

        System.out.println("Sorted!");
        System.out.println(end - start + "ms");
        ps.println(Arrays.toString(arr));
    }

    static int getMax(int[] arr) { // gets the maximum element, to figure out the number of digits given in the input
        int max = arr[0];
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] > max) max = arr[i];
        }
        return max;
    }

    static void countSort(int[] arr, int exp) {
        int[] output = new int[arr.length];
        int i;
        int[] count = new int[10];
        Arrays.fill(count, 0);

        for(i = 0; i < arr.length; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for(i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for(i = arr.length - 1; i >= 0; i--) {
            int loc = (arr[i] / exp) % 10;
            output[count[loc] - 1] = arr[i];
            count[loc]--;
        }

        for(i = 0; i < arr.length; i++) {
            arr[i] = output[i];
        }
    }

    static void radixSort(int[] arr) {
        int m = getMax(arr);
        for(int exp = 1; m/exp > 0; exp *= 10) {
            countSort(arr, exp);
        }
    }
 }
