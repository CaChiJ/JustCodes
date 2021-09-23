#include <iostream>

using namespace std;

int DP[301][301];

int main(void)
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    for (int order = 0; order < N; ++order)
    {
        int X, Y;
        scanf("%d %d", &X, &Y);

        for (int i = M; i >= X; --i)
        {
            for (int j = K; j >= Y; --j)
            {
                DP[i][j] = max(DP[i][j], DP[i - X][j - Y] + 1);
            }
        }
    }

    printf("%d", DP[M][K]);

    return 0;
}