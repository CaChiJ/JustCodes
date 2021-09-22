#include <iostream>

using namespace std;

long long DP[91][2];

int main(void)
{
    int N;
    scanf("%d", &N);

    DP[1][0] = 0;
    DP[1][1] = 1;

    for (int i = 2; i <= N; ++i)
    {
        DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
        DP[i][1] = DP[i - 1][0];
    }

    cout << DP[N][0] + DP[N][1] << endl;
    return 0;
}