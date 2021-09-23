#include <iostream>

using namespace std;

int DP[10001];

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);

    for (int k = 0; k < K; ++k)
    {
        int I, T;
        scanf("%d %d", &I, &T);

        for (int t = N; t >= T; t--)
        {
            DP[t] = max(DP[t], DP[t - T] + I);
        }
    }

    printf("%d", DP[N]);

    return 0;
}