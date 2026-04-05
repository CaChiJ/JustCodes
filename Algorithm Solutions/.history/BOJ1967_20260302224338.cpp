#include <iostream>
#include <vector>
#include <utility>

using namespace std;

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

    while (true) {
        
    }   
}