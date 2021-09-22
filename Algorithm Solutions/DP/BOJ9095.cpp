#include <iostream>
#include <stack>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

#define ff first
#define ss second

int DP[12];

int GetCaseCount(const int NODE, const int GOAL)
{
    if (NODE > GOAL)
    {
        return 0;
    }

    if (DP[NODE] != -1)
    {
        return DP[NODE];
    }

    int result = 0;

    for (int i = 1; i <= 3; ++i)
    {
        result += GetCaseCount(NODE + i, GOAL);
    }

    return DP[NODE] = result;
}

int main(void)
{
    int TC;
    scanf("%d", &TC);

    for (int tcCnt = 0; tcCnt < TC; ++tcCnt)
    {
        int N;
        scanf("%d", &N);

        for (int i = 0; i < N; ++i)
        {
            DP[i] = -1;
        }

        DP[N] = 1;
        printf("%d\n", GetCaseCount(0, N));
    }
}