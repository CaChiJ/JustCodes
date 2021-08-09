#include <iostream>
#include <vector>

using namespace std;

/*
4
0 0 0 2
2 0 0 4
0 0 2 2
0 2 0 2
*/

void printBoard(vector< vector<int> >& board) {
	cout << "===========\n";
	for(int i = 0; i < board.size(); ++i) {
		for(int j = 0; j < board[i].size(); ++j) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return;
}

int playGame(vector< vector<int> >& board, const int LEFT) {
	//printBoard(board);
	//cout << LEFT << "\n";
    // base case 
    if(LEFT == 0) {
        int maxValue = -1;
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                maxValue = max(maxValue, board[i][j]);
            }
        }
        
        return maxValue;
    }
    
    int start[2] = {0, board.size()-1};
    int end[2] = {board.size(), -1};
    int diff[2] = {1, -1};
    
    vector< vector<int> > newBoard(board.size(), vector<int>(board.size(), 0));
    int result = 0;
    for(int d = 0; d < 2; ++d) {
        newBoard = vector< vector<int> >(board.size(), vector<int>(board.size(), 0));
        
        for(int i = 0; i < board.size(); i++) {
            int last = -1;
            int size = 0;
            
            for(int j = start[d]; j != end[d]; j += diff[d]) {
                if(last == board[i][j]) {
                    last = -1;
                    newBoard[i][size] = board[i][j] * 2;
                    size++;
                } else if(board[i][j] != 0) {
                	if(last != -1) {
                		newBoard[i][size] = last;
                		size++;
					}
                    last = board[i][j];
                }
            }
            
            if(last > 0) {
                newBoard[i][size] = last;
            }
        }
        
        result = max(result, playGame(newBoard, LEFT - 1));
        newBoard = vector< vector<int> >(board.size(), vector<int>(board.size(), 0));
        
        for(int i = 0; i < board.size(); i++) {
            int last = -1;
            int size = 0;
            
            for(int j = start[d]; j != end[d]; j += diff[d]) {
                if(last == board[j][i]) {
                    last = -1;
                    newBoard[size][i] = board[j][i] * 2;
                    size++;
                } else if(board[j][i] != 0) {
                	if(last != -1) {
                		newBoard[size][i] = last;
                		size++;
                	}
                    last = board[j][i];
                }
            }
            
            if(last > 0) {
                newBoard[size][i] = last;
            }
        }
        
        result = max(result, playGame(newBoard, LEFT - 1));
    }
    
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector< vector<int> > board(N, vector<int>(N));
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << playGame(board, 5) << endl;
    
    return 0;
}
