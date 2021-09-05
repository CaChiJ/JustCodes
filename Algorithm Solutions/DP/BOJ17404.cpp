#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 1000;
int cost[MAXN][3];
int minCost[MAXN][3][3];

int GetMinCost(const int LAST_COLOR, int idx, int color) {
    if(idx == 0) {
        return color == LAST_COLOR ? INT_MAX : cost[0][color];
    }
    
    if(minCost[idx][color][LAST_COLOR] != 0) {
        return minCost[idx][color][LAST_COLOR];
    }
    
    return minCost[idx][color][LAST_COLOR] = cost[idx][color] + min(GetMinCost(LAST_COLOR, idx-1, (color + 1) % 3), GetMinCost(LAST_COLOR, idx-1, (color + 2) % 3));
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    cout << min(min(GetMinCost(0, N-1, 0), GetMinCost(1, N-1, 1)), GetMinCost(2, N-1, 2)) << endl;
    
    return 0;
}
