import java.util.*;

class Main {
    static long[] DP = new long[128];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(GetFibonacci(n));
    }

    private static long GetFibonacci(int n) {
        if (n <= 1) {
            return n;
        }

        if (DP[n] != 0) {
            return DP[n];
        }

        return DP[n] = GetFibonacci(n - 1) + GetFibonacci(n - 2);
    }
}