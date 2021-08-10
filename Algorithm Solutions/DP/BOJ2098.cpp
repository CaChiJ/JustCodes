#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int DP[16][70000];
int N;
int costs[16][16];

bool isTrue(int status, int th) {
    return (status & (1 << th)) > 0;
}

int denote(int status, int th, bool value) {
    if(value) {
        return status | (1 << th);
    } else {
        return status & (~(1 << th));
    }
}

int getMinCost(int city, int status) {
    if(DP[city][status] != -3) {
        return DP[city][status];
    }
    
    int result = -1;
    
    for(int i = 0; i < N; ++i) {
        if(!isTrue(status, i) && costs[city][i] != 0) {
            int subResult = getMinCost(i, denote(status, i, true));
            
            if(subResult != -1) {
                result = result == -1 ? subResult + costs[city][i] : min(result, subResult + costs[city][i]);
            }
        }
    }
    
    return DP[city][status] = result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> costs[i][j];
        }
    }
    
    int maxStatus = pow(2, N) - 1;
    
    
    int result = INT_MAX;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < maxStatus; j++) {
            DP[i][j] = -3;
        }
	}
	
    for(int i = 0; i < 16; ++i) {
        DP[i][maxStatus] = -1;
    }
	
    DP[0][maxStatus] = 0;
    cout << getMinCost(0, 0) << endl;
    
    return 0;
}
