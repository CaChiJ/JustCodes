#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int MAX_N = 1001;
bool gender[MAX_N];    // man : false | woman : true;
int parent[MAX_N];

typedef pair<int, pair<int, int> > Edge;
priority_queue<Edge, vector<Edge>, greater<Edge> > edge;

int find(int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void uni(int a, int b)
{
    parent[find(b)] = find(a);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
    
    for(int i = 1; i <= N; ++i) {
        char tmp;
        cin >> tmp;
        gender[i] = tmp == 'W';
    }
    
    for(int i = 0; i < M; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        edge.push({d, {u, v}});
    }
    
    int ans = 0;
    while(!edge.empty()) {
        Edge e = edge.top();
        edge.pop();
        if(find(e.second.first) != find(e.second.second) && gender[e.second.first] != gender[e.second.second]) {
            uni(e.second.first, e.second.second);
            ans += e.first;
        }
    }
    
    int root = find(1);
    for(int i = 1; i <= N; ++i) {
        if(root != find(i)) {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}
