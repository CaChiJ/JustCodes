#include <iostream>

using namespace std;

int DP[101][10001];

int main(void)
{
    int N, T;
    scanf("%d %d", &N, &T);

    for (int i = 0; i < N; ++i)
    {
        int w, c;
        scanf("%d %d", &w, &c);

        for (int j = 0; j <= T; ++j)
        {
            if (j >= w)
            {
                DP[i + 1][j] = max(DP[i][j], DP[i][j - w] + c);
            }
            else
            {
                DP[i + 1][j] = DP[i][j];
            }
        }
    }

    printf("%d", DP[N][T]);
    return 0;
}