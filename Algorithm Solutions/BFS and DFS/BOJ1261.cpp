#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;
using piii = pair<pair<int, int>, int>;

const int MAX_N = 100;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int map[MAX_N + 1][MAX_N + 1];
int cost[MAX_N + 1][MAX_N + 1];

int main(void) {
    int M, N;
    cin >> M >> N;

    memset(cost, 127, sizeof(cost));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%1d", &(map[i][j]));
        }
    }

    queue<piii> q;
    q.push({{1, 1}, 0});

    while (!q.empty()) {
        piii now = q.front();
        q.pop();
        
        int nowX = now.first.first;
        int nowY = now.first.second;

        if (cost[now.first.first][now.first.second] <= now.second) {
            continue;
        }

        cost[now.first.first][now.first.second] = now.second;

        for (int d = 0; d < 4; ++d) {
            int nX = nowX + dx[d];
            int nY = nowY + dy[d];

            if (nX <= 0 || nX > N || nY <= 0 || nY > M) {
                continue;
            }

            if (cost[nX][nY] > now.second + map[nX][nY]) {
                q.push({{nX, nY}, now.second + map[nX][nY]});
            }
        }
    }

    cout << cost[N][M] << '\n';

    return 0;
}