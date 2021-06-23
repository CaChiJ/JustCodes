#include <stdio.h>

int main(void)
{
    double radius = 0;
    scanf("%lf", &radius);
    printf("%f\n", radius * radius * radius * 3.141592 * 4.0 / 3.0);

    return 0;
}