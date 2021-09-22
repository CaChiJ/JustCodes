#include <iostream>

using namespace std;

int main(void)
{
    int DP[1001];

    DP[1] = 1;
    DP[2] = 2;

    int N;
    scanf("%d", &N);

    for (int i = 3; i <= N; ++i)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
    }

    printf("%d", DP[N]);
    return 0;
}