import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int result = 0;

        for (int i = 0; i < 5; ++i) {
            int input = scanner.nextInt();

            if (input < 40) {
                input = 40;
            }

            result += input;
        }

        System.out.println(result / 5);
    }
}