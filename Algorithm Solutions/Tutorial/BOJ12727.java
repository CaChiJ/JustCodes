import java.math.BigInteger;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int dist = scanner.nextInt();
        int result = dist / 5;
        if (dist % 5 != 0) {
            result += 1;
        }
        System.out.printf("%d%n", result);
    }
}