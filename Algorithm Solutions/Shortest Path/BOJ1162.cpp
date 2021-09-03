#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

// cost, {left, to}
typedef pair<long long, pair<int, int> > Edge;
vector< pair<int, int> > edges[10000];
bool isVisited[10000][21];
long long dist[10000][21];
int N, M, K;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    for(int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        edges[a].push_back({t, b});
        edges[b].push_back({t, a});
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= K; ++j) {
            dist[i][j] = LLONG_MAX;
        }
    }
    
    priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
    pq.push({0, {K, 0}});
    
    while(!pq.empty()) {
    	Edge edge = pq.top();
    	pq.pop();
    	
    	long long cost = edge.first;
    	int left = edge.second.first;
    	int to = edge.second.second;
    	
    	if(dist[to][left] < cost) {
    		continue;
		}
		
    	dist[to][left] = cost;
    	isVisited[to][left] = true;
    	
    	for(auto i = edges[to].begin(); i < edges[to].end(); ++i) {
			if(cost + (*i).first < dist[(*i).second][left]) {
    			pq.push({cost + (*i).first, {left, (*i).second}});
			}
			
    		if(left > 0 && cost < dist[(*i).second][left-1]) {
    			pq.push({cost, {left - 1, (*i).second}});
			}
		}
	}
	
	long long result = LLONG_MAX;
	
	for(int i = 0; i <= K; ++i) {
		result = min(result, dist[N-1][i]);
	}
	
	cout << result << '\n';
    
    return 0;
}
