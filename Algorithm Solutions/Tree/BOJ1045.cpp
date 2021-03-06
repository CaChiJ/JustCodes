#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

const int MAX_N = 50;
int parent[MAX_N];
vector<pair<int, int> > edge;

int find(int node)
{
    if(node == parent[node]) {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void unite(int a, int b)
{
    parent[find(b)] = find(a);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int ans[MAX_N];
    memset(ans, 0, sizeof(ans));
    int roadCount = 0;
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i) { parent[i] = i; }
    
    for(int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        
        for(int j = i+1; j < N; ++j) {
	    if(line[j] == 'Y') {
                if(find(i) != find(j)) {
        	    unite(i, j);
        	    roadCount++;
                
            	    ans[i]++;
            	    ans[j]++;
        	} else {
    	            edge.push_back({i, j});
		}	
	    }
        }
    }
    
    if(roadCount != N-1) {
	cout << -1 << endl;
	return 0;
    }
    
    for(int i = N-1; i < M; ++i) {
    	if(edge.empty()) {
    	    cout << -1 << endl;
    	    return 0;
	}
		
    	ans[edge.front().first]++;
    	ans[edge.front().second]++;
    	edge.erase(edge.begin());
    }
	
    for(int i = 0; i < N; ++i) {
	cout << ans[i] << ' ';
    }
    
    return 0;
}
