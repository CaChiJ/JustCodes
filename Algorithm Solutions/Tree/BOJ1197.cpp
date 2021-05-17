#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int parent[10001];
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
    
    for(int i = 0; i < 10001; ++i) { parent[i] = i; }
    
    int V, E;
    cin >> V >> E;
    
    for(int i = 0; i < E; ++i)
    {
        int A, B, W;
        cin >> A >> B >> W;
        edge.push({W, {A, B}});
    }
    
    int ans = 0;
    
    while(!edge.empty())
    {
        Edge e = edge.top();
        edge.pop();
        if(find(e.second.first) != find(e.second.second))
        {
            uni(e.second.first, e.second.second);
            ans += e.first;
        }
    }
    
    cout << ans <<endl;
    return 0;
}
