#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    long long result = 4ll;
    long long a = 0ll;
    long long b = 1ll;

    for (int i = 2; i <= N; ++i)
    {
        {
            long long c = a + b;
            a = b;
            b = c;
        }

        result += 2 * b;
    }

    printf("%lld", result);

    return 0;
}