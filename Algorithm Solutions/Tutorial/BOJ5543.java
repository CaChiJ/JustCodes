import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int burgerCost = 2001;

        for (int i = 0; i < 3; ++i) {
            int input = sc.nextInt();

            if (input < burgerCost) {
                burgerCost = input;
            }
        }

        int drinkCost = 2001;

        for (int i = 0; i < 2; ++i) {
            int input = sc.nextInt();

            if (input < drinkCost) {
                drinkCost = input;
            }
        }

        System.out.println(burgerCost + drinkCost - 50);
    }
}