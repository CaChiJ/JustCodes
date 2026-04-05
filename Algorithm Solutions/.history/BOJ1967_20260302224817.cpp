#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int visited[10000];

int main(void) {
    int N;
    cin >> N;
    vector<pair<int, int>> graph(N);

    for (int i = 0; i < N - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greator<pair<int, int>>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        pair<int, int> cur = pq.front();
        pq.pop();
        int dist = cur.first
        int node = cur.second;

        if (isVisited[node]) {
            return;
        }

        for (int i = 0; i < graph[node].size(); ++i) {
            int nextNode = graph[node][i].first;
            int nextWeight = graph[node][i].second;

            if (isVisited[nextNode]) {
                continue;
            }

            pq.push({dist + nextWeight, nextNode})
        }
    }
}