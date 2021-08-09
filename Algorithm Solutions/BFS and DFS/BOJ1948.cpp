#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector< pair<int, int> > DP;
vector< vector< pair<int, int> > > edges;
vector< vector< bool > > isCounted;

pair<int, int> DFS(int start, int end) {
    if(DP[start].first != -1) {
        return DP[start];
    }
    
    for(vector< pair<int, int> >::iterator edge = edges[start].begin(); edge < edges[start].end(); ++edge) {
        pair<int, int> subResult = DFS((*edge).first, end);
        subResult.first += (*edge).second;
        subResult.second += 1;
        if(subResult.first > DP[start].first) {
            DP[start] = subResult;
        }
    }
    
    return DP[start];
}

int getEdgeCount(int now, int cost, int tSum) {
    int count = 0;
    
    if(DP[now].first + cost == tSum) {
        count += 1;
    } else {
        return 0;
    }
    
    for(pair<int, int> edge : edges[now]) {
        if(!isCounted[now][edge.first]) {
            count += getEdgeCount(edge.first, edge.second, DP[now].first);
            isCounted[now][edge.first] = true;
        }
    }
    
    return count;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, M;
    cin >> N >> M;
    
    DP.resize(N + 1, make_pair(-1, -1));
    edges.resize(M);
    isCounted = vector< vector<bool> >(N + 1, vector<bool>(N + 1, false));
    
    for(int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        
        edges[a].push_back({b, t});
    }
    
    int start, end;
    cin >> start >> end;
    
    DP[end] = make_pair(0, 0);
    pair<int, int> result = DFS(start, end);
    cout << result.first << endl;
    cout << getEdgeCount(1, 0, result.first) - 1<< endl;
    
    return 0;
}
