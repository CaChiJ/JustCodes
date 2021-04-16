#include <stdio.h>

int main(void)
{
    int a = 10;
    char * b = "hello";
    double c = 3.1;

    printf("%d%s%.1f\n", a, b, c);

    system("pause");
    return 0;
}