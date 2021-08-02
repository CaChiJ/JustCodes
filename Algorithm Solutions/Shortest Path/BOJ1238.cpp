#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

typedef pair<int, int> Edge;
vector< vector<Edge> > edges;
vector< vector<Edge> > edgesR;
vector<int> dist;
vector<int> distR;

int main(void) {
    int N, M, X;
    cin >> N >> M >> X;
    
    edges.resize(N+1);
    edgesR.resize(N+1);
    dist.resize(N+1);
    distR.resize(N+1);
    fill(dist.begin(), dist.end(), -1);
    fill(distR.begin(), distR.end(), -1);
    
    for(int i = 0; i < M; ++i) {
        int from, to, taken;
        cin >> from >> to >> taken;
        
        edges[from].push_back({to, taken});
        edgesR[to].push_back({from, taken});
    }
    
    priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
    pq.push({0, X});
    
    while(!pq.empty()) {
        int to, taken;
        tie(taken, to) = pq.top();
        pq.pop();
        
        if(dist[to] != -1) {
            continue;
        }
        
        dist[to] = taken;
        
        for(Edge e : edges[to]) {
            if(dist[e.first] != -1) {
                continue;
            }
            
            pq.push({taken + e.second, e.first});
        }
    }
    
    pq.push({0, X});
    
    while(!pq.empty()) {
        int to, taken;
        tie(taken, to) = pq.top();
        pq.pop();
        
        if(distR[to] != -1) {
            continue;
        }
        
        distR[to] = taken;
        
        for(Edge e : edgesR[to]) {
            if(distR[e.first] != -1) {
                continue;
            }
            
            pq.push({taken + e.second, e.first});
        }
    }
    
    int maxT = -1;
    
    for(int i = 1; i <= N; ++i) {
        if(dist[i] + distR[i] > maxT) {
            maxT = dist[i] + distR[i];
        }
    }
    
    cout << maxT << '\n';
    return 0;
}
