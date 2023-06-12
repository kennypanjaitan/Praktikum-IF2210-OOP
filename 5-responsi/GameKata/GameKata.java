import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
        Map<String, Integer> titoMap = new HashMap<>();
        Map<String, Integer> wiwidMap = new HashMap<>();
        for (String t : tito) {
            titoMap.put(t, titoMap.getOrDefault(t, 0) + 1);
        }
        for (String w : wiwid) {
            wiwidMap.put(w, wiwidMap.getOrDefault(w, 0) + 1);
        }
        for (String t : titoMap.keySet()) {
            if (wiwidMap.containsKey(t)) {
                System.out.println(t);
            }
        }
    }

    public static void main(String[] args) {
        //input string
        Scanner sc = new Scanner(System.in);
        String[] tito = sc.nextLine().split(" ");
        String[] wiwid = sc.nextLine().split(" ");
        run(tito, wiwid);
    }
}