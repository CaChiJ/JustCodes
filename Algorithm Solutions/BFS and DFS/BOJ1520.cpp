#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int N, M;

int map[503][503];
int noc[503][503];

int getNumberOfCases(int r, int c) {
    if(noc[r][c] != -1) {
        return noc[r][c];
    }
    
    int result = 0;
    
    for(int d = 0; d < 4; ++d) {
        if(r + dy[d] < 0 || c + dx[d] < 0 || r + dy[d] >= N || c + dx[d] >= M) {
            continue;
        }
        
        if(map[r + dy[d]][c + dx[d]] < map[r][c]) {
            result += getNumberOfCases(r + dy[d], c + dx[d]);
        }
    }
    
    return noc[r][c] = result;
}

int main(void) {
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> map[i][j];
            noc[i][j] = -1;
        } 
    }
    
    noc[N-1][M-1] = 1;
    
    cout << getNumberOfCases(0, 0) << endl;
    
    return 0;
}
