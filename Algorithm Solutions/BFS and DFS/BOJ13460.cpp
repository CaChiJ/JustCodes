#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

char board[10][10];
int N, M;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
const char wall = '#';
const char space = '.';
const char hole = 'O';
const char red = 'R';
const char blue = 'B';
    

void printBoard() {
	cout << "=================\n";
	
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			cout << board[i][j] << ' ';
		}
		
		cout << '\n';
	}
}

pair<int, int> nextPos(pair<int, int> nowPos, int dir) {
    while(true) {
        int newY = nowPos.first + dy[dir];
        int newX = nowPos.second + dx[dir];
        
        if(board[newY][newX] == hole) {
            nowPos.first = newY;
            nowPos.second = newX;
            break;
        } else if(board[newY][newX] == '.') {
            nowPos.first = newY;
            nowPos.second = newX;
        } else {
            break;
        }
    }
    
    return nowPos;
}

int main(void) {
    cin >> N >> M;
    
    queue< pair< pii, pii > > q;
    pair<int, int> redInit;
    pair<int, int> blueInit;
    
    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < M; ++c) {
            cin >> board[r][c];
            
            if(board[r][c] == red) {
            	redInit.first = r;
            	redInit.second = c;
            	board[r][c] = space;
			} else if(board[r][c] == blue) {
				blueInit.first = r;
				blueInit.second = c;
				board[r][c] = space;
			}
        }
    }
    
    q.push({redInit, blueInit});
    
    int result = -1;
    
    for(int cycle = 0; cycle < 10 && !q.empty(); ++cycle) {
    	//cout << cycle << ' ';
        int qSize = q.size();
        
        for(int i = 0; i < qSize; ++i) {
            pair< pii, pii > top = q.front();
            q.pop();
            
            int redR = top.first.first;
            int redC = top.first.second;
            int blueR = top.second.first;
            int blueC = top.second.second;
            
            for(int d = 0; d < 4; ++d) {
                if(redR * dy[d] + redC * dx[d] >= blueR * dy[d] + blueC * dx[d]) {
                	int tmp = -1;
                	
                    board[blueR][blueC] = blue;
                    pii rNext = nextPos(make_pair(redR, redC), d);
                    board[blueR][blueC] = space;
                    
                    if(board[rNext.first][rNext.second] == hole) {
                        tmp = cycle + 1;
                    } else {
                    	board[rNext.first][rNext.second] = red;
					}
					
                    pii bNext = nextPos(make_pair(blueR, blueC), d);
                    
                    // test code 1
                    char tmp2 = board[bNext.first][bNext.second];
                    board[bNext.first][bNext.second] = blue;
                    char tmp3 = board[rNext.first][rNext.second];
                    board[rNext.first][rNext.second] = red;
                    printBoard();
                    board[bNext.first][bNext.second] = tmp2;
                    board[rNext.first][rNext.second] = tmp3;
                    
                    if(board[bNext.first][bNext.second] == hole) {
                        continue;
                    } else {
                    	board[rNext.first][rNext.second] = space;
					}
                    
                    if(tmp != -1) {
                    	result = tmp;
                        cycle = 10;
                        i = qSize;
                        break;
                    }
                    
                    q.push({rNext, bNext});
                } else {
                    board[redR][redC] = red;
                    pii bNext = nextPos(make_pair(blueR, blueC), d);
                    board[redR][redC] = space;
                    
                    if(board[bNext.first][bNext.second] == hole) {
						continue;
                    }
                    
                    board[bNext.first][bNext.second] = blue;
                    pii rNext = nextPos(make_pair(redR, redC), d);
                    
                    // test code 1
                    char tmp2 = board[bNext.first][bNext.second];
                    board[bNext.first][bNext.second] = blue;
                    char tmp3 = board[rNext.first][rNext.second];
                    board[rNext.first][rNext.second] = red;
                    printBoard();
                    board[bNext.first][bNext.second] = tmp2;
                    board[rNext.first][rNext.second] = tmp3;
                    
                    board[bNext.first][bNext.second] = space;
                    
                    if(board[rNext.first][rNext.second] == hole) {
                        result = cycle + 1;
                        cycle = 10;
                        i = qSize;
                        break;
                    }
                    
                    q.push({rNext, bNext});
                }   
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
} 
