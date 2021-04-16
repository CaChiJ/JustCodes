#include <stdio.h>

int main(void)
{
    int num1;
    int num2;
    int num3;

    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 <= num2 && num1 <= num3)
    {
        printf("min: %d\n", num1);

        if (num2 >= num3)
        {
            printf("max: %d", num2);
        }
        else
        {
            printf("max: %d", num3);
        }
    }
    else if(num2 <= num3)
    {
        printf("min: %d\n", num2);

        if(num1 >= num3)
        {
            printf("max: %d", num1);
        }
        else
        {
            printf("max: %d", num3);
        }
    }
    else
    {
        printf("min: %d\n", num3);

        if(num1 >= num2)
        {
            printf("max: %d", num1);
        }
        else
        {
            printf("max: %d", num2);
        }
    }

    printf("\n");
    system("pause");
    return 0;
}