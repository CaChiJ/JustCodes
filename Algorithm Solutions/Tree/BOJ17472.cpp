#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair< int, pair<int, int> > Edge;
priority_queue< Edge, vector<Edge>, greater<Edge> > edges;

int parent[103];

int find(int node) {
    if(parent[node] == node) {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void uni(int a, int b) {
    parent[find(b)] = find(a);
}

int getNodeNum(int r, int c, int m) {
    return r * m + c;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, M;
    cin >> N >> M;
    
    vector< vector<bool> > map(N, vector<bool>(M, false));
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    for(int i = 0; i < N * M; ++i) {
        parent[i] = i;
    }
    
    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < M; ++c) {
            int tmp;
            cin >> tmp;
            map[r][c] = tmp == 1;
        }
    }
    
    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < M; ++c) {
        	if(!map[r][c]) {
        		continue;
			}
			
            for(int d = 0; d < 4; ++d) {
                int newR = r + dy[d];
                int newC = c + dx[d];
                    
                if(newR < 0 || newR >= N || newC < 0 || newC >= M) {
                    continue;
                }
                    
                if(map[newR][newC]) {
                    uni(getNodeNum(newR, newC, M), getNodeNum(r, c, M));
                }
            }
        }
    }
    
    for(int r = 0; r < N; ++r) {
        int lastIsland = -1;
        int lastIdx = -1;
        
        for(int c = 0; c < M; ++c) {
            if(!map[r][c]) {
                continue;
            }
            
            int nowNode = find(getNodeNum(r, c, M));
            
            if(nowNode != lastIsland && lastIsland != -1 && c - lastIdx - 1 > 1) {
                edges.push({c - lastIdx - 1, {lastIsland, nowNode}});
            }
                
            lastIsland = nowNode;
            lastIdx = c;
        }
    }
    
    for(int c = 0; c < M; ++c) {
        int lastIsland = -1;
        int lastIdx = -1;
        
        for(int r = 0; r < N; ++r) {
            if(!map[r][c]) {
                continue;
            }
            
            int nowNode = find(getNodeNum(r, c, M));
            
            if(nowNode != lastIsland && lastIsland != -1 && r - lastIdx - 1 > 1) {
                edges.push({r - lastIdx - 1, {lastIsland, nowNode}});
            }
                
            lastIsland = nowNode;
            lastIdx = r;
        }
    }
    
    int result = 0;
    
    while(!edges.empty()) {
        Edge edge = edges.top();
        edges.pop();
        
        if(find(edge.second.first) == find(edge.second.second)) {
            continue;
        }
        
        result += edge.first;
        uni(edge.second.first, edge.second.second);
    }
    
    int root = -1;
    
    for(int r = 0; r < N; ++r) {
    	for(int c = 0; c < M; ++c) {
    		if(!map[r][c]) {
    			continue;
			}
			
			
			if(root == -1) {
				root = find(getNodeNum(r, c, M));
			}
			
    		if(find(getNodeNum(r, c, M)) != root) {
    			result = -1;
    			r = N;
    			c = M;
			}
		}
	}
    
    cout << result << '\n';
    
    return 0;
}
