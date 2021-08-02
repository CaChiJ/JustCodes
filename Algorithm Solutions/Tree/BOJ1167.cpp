#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> Pii;
vector< vector<Pii> > edges;

Pii dfs(vector< vector<Pii> > &edges, vector<bool> &isVisited, int start, int distance) {
    Pii result = {distance, start};
    isVisited[start] = true;
    
    for(int i = 0; i < edges[start].size(); ++i) {
        if(isVisited[edges[start][i].first]) {
            continue;
        }
        
        Pii tmp = dfs(edges, isVisited, edges[start][i].first, distance + edges[start][i].second);
        
        if(tmp.first > result.first) {
            result = tmp;
        }
    }
    
    return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int V;
    cin >> V;
    
    edges.resize(V);
    
    for(int i = 0; i < V; ++i) {
        int v1;
        cin >> v1;
        v1--;
        
        while(true) {
            int v2, d;
            cin >> v2;
            
            if(v2 == -1) {
                break;
            }
            
            v2--;
            
            cin >> d;
            
            edges[v1].push_back(make_pair(v2, d));
            edges[v2].push_back(make_pair(v1, d));
        }
    }
    
    vector<bool> isVisited(V, false);
    Pii subResult = dfs(edges, isVisited, 0, 0);
    
    fill(isVisited.begin(), isVisited.end(), false);
    Pii result = dfs(edges, isVisited, subResult.second, 0);
    
    cout << result.first << '\n';
    
    return 0;
}
