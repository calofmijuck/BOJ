import java.util.*;
import java.io.*;

public class TestCase {
    public static void main(String[] args) throws FileNotFoundException {
        PrintStream ps = new PrintStream(new File("input.txt"));
        int length = 100000;

        Random rand = new Random();

        ps.println(length);
        for(int i = 0; i < length; i++) {
            ps.println(rand.nextInt(10 * length) + 1);
        }

        // Reverse Order
        // for(int i = length; i > 0; i--) {
        //     ps.println(i);
        // }
    }
}
