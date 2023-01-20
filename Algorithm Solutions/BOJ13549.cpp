#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 100000;
int dist[MAX_N + 1];

int main(void) {
    int N, K;
    cin >> N >> K;

    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(N);
    
    int cycle = 0;

    while (!q.empty()) {
        int qSize = q.size();
        
        for (int qCnt = 0; qCnt < qSize; ++qCnt) {
            int now = q.front();
            q.pop();

            if (dist[now] != -1) {
                continue;
            }

            while (now <= MAX_N && dist[now] == -1) {
                dist[now] = cycle;

                int candidates[2] = {now - 1, now + 1};

                for (int i = 0; i < 2; ++i) {
                    int candidate = candidates[i];

                    if (candidate < 0 || candidate > MAX_N || dist[candidate] != -1) {
                        continue;
                    }

                    q.push(candidate);
                }

                now *= 2;
            }
        }

        cycle++;
    }

    cout << dist[K] << '\n';
    
    return 0;
}