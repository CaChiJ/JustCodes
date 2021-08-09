#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

/*
4
0 0 0 2
2 0 0 4
0 0 2 2
0 2 0 2
*/

int N;

void printBoard(int board[][20]) {
	cout << "===========\n";
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return;
}

int playGame(int board[][20], const int LEFT, const int MAX_RESULT) {
	//cout << LEFT << ' ' << MAX_RESULT << '\n';
    // base case
    if(LEFT == 0) {
        int maxValue = -1;
        
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                maxValue = max(maxValue, board[i][j]);
            }
        }
        
        return maxValue;
    }
    
    int start[2] = {0, N - 1};
    int end[2] = {N, -1};
    int diff[2] = {1, -1};
    
    int newBoard[N][20];
    int result = 0;
    bool isChanged = false;
    
    for(int d = 0; d < 2; ++d) {
    	int localMax = 0;
        for(int i = 0; i < N; ++i) {
        	for(int j = 0; j < N; ++j) {
        		newBoard[i][j] = 0;
			}
		}
        isChanged = false;
        
        for(int i = 0; i < N; i++) {
            int last = -1;
            int size = start[d];
            
            for(int j = start[d]; j != end[d]; j += diff[d]) {
                if(last == board[i][j]) {
                    last = -1;
                    newBoard[i][size] = board[i][j] * 2;
                    localMax = max(localMax, newBoard[i][size]);
                    size+=diff[d];
                    isChanged = true;
                } else if(board[i][j] != 0) {
                	if(last != -1) {
                		newBoard[i][size] = last;
                		localMax = max(localMax, newBoard[i][size]);
                    	size+=diff[d];
                		isChanged = true;
					}
                    last = board[i][j];
                }
            }
            
            if(last > 0) {
                newBoard[i][size] = last;
                localMax = max(localMax, newBoard[i][size]);
                isChanged = true;
            }
        }
        
        /*
        cout << d << " 0************\n";
		printBoard(board);
		printBoard(newBoard);
		cout << localMax << endl;
		cout << "************\n";
		*/
		
        if(isChanged && localMax * pow(2, max(LEFT - 1, 0)) > MAX_RESULT) {
        	result = max(result, playGame(newBoard, LEFT - 1, max(result, MAX_RESULT)));
		}
		
		localMax = 0;
        for(int i = 0; i < N; ++i) {
        	for(int j = 0; j < N; ++j) {
        		newBoard[i][j] = 0;
			}
		}
        isChanged = false;
        
        for(int i = 0; i < N; i++) {
            int last = -1;
            int size = start[d];
            
            for(int j = start[d]; j != end[d]; j += diff[d]) {
                if(last == board[j][i]) {
                    last = -1;
                    newBoard[size][i] = board[j][i] * 2;
                	localMax = max(localMax, newBoard[size][i]);
                    size += diff[d];
                	isChanged = true;
                } else if(board[j][i] != 0) {
                	if(last != -1) {
                		newBoard[size][i] = last;
                		localMax = max(localMax, newBoard[size][i]);
                    	size += diff[d];
                		isChanged = true;
                	}
                    last = board[j][i];
                }
            }
            
            if(last > 0) {
                newBoard[size][i] = last;
                localMax = max(localMax, newBoard[size][i]);
                isChanged = true;
            }
        }
        
        /*
		cout << d << " 1************\n";
		printBoard(board);
		printBoard(newBoard);
		cout << "************\n";
		*/
		
        if(isChanged && localMax * pow(2, max(LEFT - 1, 0)) > MAX_RESULT) {
    	    result = max(result, playGame(newBoard, LEFT - 1, max(result, MAX_RESULT)));
    	}
    }
    
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int board[N][20];
	memset(board, 0, sizeof(board));
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << playGame(board, 10, 0) << endl;
    
    return 0;
}
