#include <stdio.h>

int main(void)
{
    int dan;
    scanf("%d", &dan);

    for(int i = 1; i < 10; ++i)
    {
        printf("%d*%d=%d\n", dan, i, dan*i);
    }

    system("pause");
    return 0;
}