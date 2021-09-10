import java.util.*;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger N = scanner.nextBigInteger();
        BigInteger M = scanner.nextBigInteger();
        scanner.close();

        System.out.println(N.divide(M));
        System.out.println(N.mod(M));
    }
}