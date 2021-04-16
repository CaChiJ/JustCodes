#include <stdio.h>

int main(void)
{
    float num1 = 1.23456789f;
    float num2 = 0.0000123456789f;

    printf("1) %.10f %.10f\n", num1, num2);
    printf("2) %e %e\n", num1, num2);
    printf("3) %E %E\n", num1, num2);
    printf("4) %g %g\n", num1, num2);
    printf("5) %G %G\n", num1, num2);

    system("pause");
    return 0;
}