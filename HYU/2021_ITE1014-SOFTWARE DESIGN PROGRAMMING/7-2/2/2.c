#include <stdio.h>

int main(void)
{
    while(1)
    {
        char ch;
        
        do
        {
            scanf("%c", &ch);
        } while(ch == '\n');
        
        if(65 <= ch && ch <= 90)
        {
            printf("-> %c\n", ch + 32);
            continue;
        }
        
        if(97 <= ch && ch <= 122)
        {
            printf("-> %c\n", ch - 32);
            continue;
        }

        if(48 <= ch && ch <= 57)
        {
            printf("-> %c\n", ch);
            continue;
        }

        printf("exit\n");
        break;
    }

    system("pause");
    return 0;
}