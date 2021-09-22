#include <iostream>

using namespace std;

int DP[1001];

int main(void)
{
    const int MOD = 10007;

    int N;
    scanf("%d", &N);

    DP[1] = 1;
    DP[2] = 3;

    for (int i = 3; i <= N; ++i)
    {
        DP[i] = (DP[i - 1] + DP[i - 2] * 2) % MOD;
    }

    cout << DP[N] << '\n';
    return 0;
}