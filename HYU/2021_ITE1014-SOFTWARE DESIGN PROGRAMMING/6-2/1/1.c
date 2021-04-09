#include <stdio.h>

int main(void)
{
    int dan;
    scanf("%d", &dan);

    int i = 1;
    while(i < 10)
    {
        printf("%d*%d=%d\n", dan, i, dan * i);
        ++i;
    }

    system("pause");
    return 0;
}