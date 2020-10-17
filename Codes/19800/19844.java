import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static int ans = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<String> list = new ArrayList<>();
        String[] arr = br.readLine().split(" ");
        for (String s : arr) {
            int idx = s.indexOf('-');
            if (idx >= 0) {
                String[] tmp = s.split("-");
                for (String t : tmp)
                    list.add(t);
            } else
                list.add(s);
        }
        for (String s : list)
            process(s);
        System.out.println(ans);
    }

    public static void process(String s) {
        if (s.length() < 3) {
            ans++;
            return;
        }
        char c = s.charAt(0);
        char d = s.charAt(1);
        char e = s.charAt(2);
        if (d == '\'') {
            if ((c == 'c' || c == 'j' || c == 'n' || c == 'm' || c == 't' || c == 's' || c == 'l' || c == 'd')
                    && (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u' || e == 'h')) {
                ans += 2;
                return;
            }
        } else if (e == '\'') {
            if (c == 'q' && d == 'u' && s.length() >= 4) {
                char f = s.charAt(3);
                if (f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u' || f == 'h') {
                    ans += 2;
                    return;
                }
            }
        }
        ans++;
    }
}
