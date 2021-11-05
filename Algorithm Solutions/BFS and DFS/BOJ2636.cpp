#include <iostream>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

const int MAX_R = 100;
const int MAX_C = 100;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

bool isVisited[MAX_R][MAX_C];
queue<pair<int, int>> q;
int map[MAX_R][MAX_C];
int R, C;

void dfs(int r, int c)
{
    stack<pair<int, int>> stk;
    stk.push(make_pair(r, c));

    while (!stk.empty())
    {
        int r = stk.top().first;
        int c = stk.top().second;
        stk.pop();

        for (int d = 0; d < 4; ++d)
        {
            int nextR = r + dr[d];
            int nextC = c + dc[d];

            if (0 <= nextR && nextR < R && 0 <= nextC && nextC < C && !isVisited[nextR][nextC])
            {
                isVisited[nextR][nextC] = true;

                if (map[nextR][nextC] == 0)
                {
                    stk.push(make_pair(nextR, nextC));
                }
                else
                {
                    q.push(make_pair(nextR, nextC));
                }
            }
        }
    }
}

int main(void)
{
    cin >> R >> C;

    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            cin >> map[r][c];
        }
    }

    {
        for (int r = 0; r < R; ++r)
        {
            dfs(r, -1);
            dfs(r, C);
        }

        for (int c = 0; c < C; ++c)
        {
            dfs(-1, c);
            dfs(R, c);
        }
    }

    int cycle = 0;
    int qSize = 0;

    while (!q.empty())
    {
        qSize = q.size();
        cycle++;

        for (int qCnt = 0; qCnt < qSize; ++qCnt)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int d = 0; d < 4; ++d)
            {
                int nextR = r + dr[d];
                int nextC = c + dc[d];

                if (0 <= nextR && nextR < R && 0 <= nextC && nextC < C && !isVisited[nextR][nextC])
                {
                    isVisited[nextR][nextC] = true;

                    if (map[nextR][nextC] == 0)
                    {
                        dfs(nextR, nextC);
                    }
                    else
                    {
                        q.push(make_pair(nextR, nextC));
                    }
                }
            }
        }
    }

    printf("%d\n%d", cycle, qSize);

    return 0;
}