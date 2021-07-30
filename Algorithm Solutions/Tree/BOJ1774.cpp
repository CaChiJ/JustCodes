#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

typedef pair< double, pair<int, int> > Edge;
priority_queue< Edge, vector<Edge>, greater<Edge> > edges;
pair<int, int> position[1004];

int parent[1004];

int find(int node) {
    if(parent[node] == node) {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void uni(int a, int b) {
    parent[find(b)] = find(a);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    double result = 0.0;
    
    for(int i = 0; i < 1004; ++i) {
        parent[i] = i;
    }
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;
        position[i] = make_pair(x, y);
    }
    
    for(int i = 1; i <= N; ++i) {
        for(int j = i + 1; j <= N; ++j) {
            edges.push(make_pair(sqrt(pow(position[i].first - position[j].first, 2.0) + pow(position[i].second - position[j].second, 2.0)), make_pair(i, j)));
        }
    }
    
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }
    
    while(!edges.empty()) {
        Edge edge = edges.top();
        edges.pop();
        
        if(find(edge.second.first) == find(edge.second.second)) {
            continue;
        }
        
        uni(edge.second.first, edge.second.second);
        result += edge.first;
    }
    
    cout.precision(2);
    cout << fixed << (int)(result * 100 + 0.5) / 100.0 << endl;
    return 0;
}
