#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> Edge;
vector< vector<Edge> > edges;
vector<int> itemCount;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, R;
    cin >> N >> M >> R;
    
    itemCount.resize(N);
    edges.resize(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> itemCount[i];
    }
    
    for(int i = 0; i < R; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        
        edges[a-1].push_back({b-1, l});
        edges[b-1].push_back({a-1, l});
    }
    
    int maxCount = -1;
    
    for(int start = 0; start < N; ++start) {
        priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
        pq.push({0, start});
        
        int count = 0;
        int dist[N];
        fill(dist, dist+N, -1);
        
        while(!pq.empty()) {
            int to, taken;
            tie(taken, to) = pq.top();
            pq.pop();
            
            if(dist[to] != -1) {
                continue;
            }
            
            dist[to] = taken;
            if(dist[to] <= M) {
                count += itemCount[to];
            }
            
            for(Edge edge : edges[to]) {
                if(dist[edge.first] != -1) {
                    continue;
                }
                
                pq.push({edge.second + taken, edge.first});
            }
        }
        
        if(count > maxCount) {
            maxCount = count;
        }
    }
    
    cout << maxCount << '\n';
    
    return 0;
}
