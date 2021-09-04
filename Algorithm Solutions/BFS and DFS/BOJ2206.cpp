#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int map[1002][1002];
bool isVisited[1002][1002][2];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main(void) {
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i = 0; i < N + 2; ++i) {
        map[i][0] = 1;
        map[i][M+1] = 1;
    }
    
    for(int i = 0; i < M + 2; ++i) {
        map[0][i] = 1;
        map[N+1][i] = 1;
    }
    
    queue< pair< pair<int,int>, int > > q;
    q.push({{1, 1}, 0});
    
    int cycle = 0;
    
    while(!q.empty()) {
        cycle++;
        int qSize = q.size();
        
        for(int i = 0; i < qSize; ++i) {
            pair< pair<int, int>, int > now = q.front();
            q.pop();
            
            int nowR = now.first.first;
            int nowC = now.first.second;
            int nowA = now.second;
            
            if(isVisited[nowR][nowC][nowA]) {
            	continue;
			}
			
            isVisited[nowR][nowC][nowA] = true;
            
            if(nowR == N && nowC == M) {
                cout << cycle << endl;
                return 0;
            }
            
            for(int d = 0; d < 4; ++d) {
                int nextR = nowR + dy[d];
                int nextC = nowC + dx[d];
                
                if(nextR == 0 || nextR == N+1 || nextC == 0 || nextC == M+1) {
                	continue;
				}
                
                if(map[nextR][nextC] == 1) {
	                if(nowA == 0 && !isVisited[nextR][nextC][1]) {
	                    q.push({{nextR, nextC}, 1});
                	}
                } else {
                	if(!isVisited[nextR][nextC][nowA]) {
                		q.push({{nextR, nextC}, nowA});
					}
				}
                
            }
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}
