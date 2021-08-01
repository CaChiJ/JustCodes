#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void printMap(vector< vector<char> > &map) {
	cout << "==============================\n";
	
	for(int i = 0; i < map.size(); ++i) {
		for(int j = 0; j < map[i].size(); ++j) {
			cout << map[i][j];
		}
		
		cout << '\n';
	}
	
	cout << "==============================\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for(int tcCnt = 0; tcCnt < T; ++tcCnt) {
        int H, W;
        cin >> H >> W;
        
        vector< vector<char> > map(H+2, vector<char>(W+2));
        
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                char tmp;
                cin >> tmp;
                map[i+1][j+1] = tmp;
            }
        }
        
        for(int i = 0; i < H+2; ++i) {
            map[i][0] = map[i][W+1] = '.';
        }
        
        for(int i = 0; i < W+2; ++i) {
            map[0][i] = map[H+1][i] = '.';
        }
        
        string keys;
        cin >> keys;
        
        vector<bool> haveKey('z'+1, false);
    	
    	for(auto key = keys.begin(); key < keys.end(); ++key) {
    		haveKey[*key - 32] =true;
		}
        
        queue< pair<int, int> > q;
        q.push(make_pair(0, 0));
        vector< vector< pair<int, int> > > doorPos('z'+1);
        vector< vector<bool> > isVisited(H+2, vector<bool>(W+2, false));
        
        int result = 0;
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(isVisited[row][col]) {
                continue;
            }
            
            isVisited[row][col] = true;
            
            
            if(map[row][col] == '$') {
                result++;
            } else if('a' <= map[row][col] && map[row][col] <= 'z') {
                haveKey[map[row][col] - 32] = true;
                
                for(int i = 0; i < doorPos[map[row][col]-32].size(); ++i) {
                    q.push(doorPos[map[row][col]-32][i]);
                }
            } else if('A' <= map[row][col] && map[row][col] <= 'Z') {
                if(!haveKey[map[row][col]]) {
                    doorPos[map[row][col]].push_back(make_pair(row, col));
                    isVisited[row][col] = false;
            		
                    continue;
                }
            }
            
			// for debugging
			//char tmpc = map[row][col];
            //map[row][col] = '@';
            //printMap(map);
            //map[row][col] = tmpc;
            
            for(int d = 0; d < 4; ++d) {
                int nextRow = row + dy[d];
                int nextCol = col + dx[d];
                
                if(nextRow < 0 || nextRow >= H+2 
                   || nextCol < 0 || nextCol >= W+2
                   || map[nextRow][nextCol] == '*') {
                    continue;
                }
                
                q.push(make_pair(nextRow, nextCol));
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}

