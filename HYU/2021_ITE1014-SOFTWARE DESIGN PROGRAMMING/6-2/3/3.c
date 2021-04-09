#include <stdio.h>

int main(void)
{
    const char star = '*';

    int num;
    scanf("%d", &num);

    for(int i = 1; i <= num; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            printf("%c ", star);
        }

        printf("\n");
    }

    system("pause");
    return 0;
}