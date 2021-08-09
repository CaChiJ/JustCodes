#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int SIZE = 9;
    
int map[SIZE][SIZE];
int isExist[3][SIZE]; // 0:row 1:column 2:block
bool isInited[SIZE][SIZE];

bool isTrue(int a, int th) {
    return (a & (1 << (th - 1))) > 0;
}

void marking(int& a, int th, bool value) {
    if(value) {
        a = a | (1 << (th - 1));
    } else {
        a = a & (-1 ^ (1 << (th - 1)));
    }
}

int getBlockNum(int row, int col) {
    return row / 3 * 3 + col / 3;
}

bool DFS(int r, int c) {
	if(r >= SIZE) {
		return true;
	}
	
    if(isInited[r][c]) {
        return DFS(r + (c + 1) / SIZE, (c + 1) % SIZE);
    }
            
	bool result = false;
    int remain = ~(isExist[0][r] | isExist[1][c] | isExist[2][getBlockNum(r, c)]);
            
    for(int i = 1; i <= SIZE; ++i) {
        if(isTrue(remain, i)) {
            map[r][c] = i;
            marking(isExist[0][r], map[r][c], true);
            marking(isExist[1][c], map[r][c], true);
            marking(isExist[2][getBlockNum(r, c)], map[r][c], true);
            
            result = DFS(r + (c + 1) / SIZE, (c + 1) % SIZE);
            
            marking(isExist[0][r], map[r][c], false);
            marking(isExist[1][c], map[r][c], false);
            marking(isExist[2][getBlockNum(r, c)], map[r][c], false);
            
        	if(result) {
            	break;
			}
        }
    }
    
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    
    for(int r = 0; r < SIZE; ++r) {
        for(int c = 0; c < SIZE; ++c) {
            scanf("%1d", &map[r][c]);
            
            if(map[r][c] != 0) {
                marking(isExist[0][r], map[r][c], true);
                marking(isExist[1][c], map[r][c], true);
                marking(isExist[2][getBlockNum(r, c)], map[r][c], true);
                isInited[r][c] = true;
            }
        }
    }
    
    DFS(0, 0);
    
    // print answer
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            printf("%d", map[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}
