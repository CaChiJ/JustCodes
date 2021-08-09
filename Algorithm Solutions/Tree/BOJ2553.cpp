#include <iostream>
#include <vector>

using namespace std;

int DP[1000003][2];
bool isVisited[1000003];

vector< vector<int> > edge;

int GetMinCount(int node, int status) {
	
    if(isVisited[node]) {
        return DP[node][status];
    }
    
    isVisited[node] = true;
    
    for(vector<int>::iterator i = edge[node].begin(); i < edge[node].end(); ++i) {
        if(isVisited[*i]) {
            continue;
        }
        
        DP[node][0] += GetMinCount(*i, 1);
        DP[node][1] += min(GetMinCount(*i, 0), GetMinCount(*i, 1));
    }
    
    DP[node][1] += 1;
    
    return DP[node][status];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int N;
    cin >> N;
    
    edge.resize(N + 1);
    
    for(int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    cout << min(GetMinCount(1, 0), GetMinCount(1, 1)) << endl;
    
    return 0;
}
