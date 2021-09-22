#include <iostream>

using namespace std;

int main(void)
{
    int N;
    scanf("%d", &N);

    int P[N + 1];

    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", P + i);
    }

    int DP[N + 1];
    DP[0] = 0;
    DP[1] = P[1];

    for (int i = 2; i <= N; ++i)
    {
        DP[i] = -1;
        for (int j = 0; j < i; ++j)
        {
            DP[i] = max(DP[i], DP[j] + P[i - j]);
        }
    }

    cout << DP[N] << '\n';

    return 0;
}