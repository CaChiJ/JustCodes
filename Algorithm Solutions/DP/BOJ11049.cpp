#include <iostream>
#include <utility>

using namespace std;

int cost[503][503];
pair<int, int> matrixes[503];

int getMinCost(int start, int end) {
    if(cost[start][end] != -1) {
        return cost[start][end];
    }
    
    int minCost = 987654321;
    
    for(int i = start+1; i < end; ++i) {
        minCost = min(minCost, getMinCost(start, i) + getMinCost(i, end) + matrixes[start].first * matrixes[i].first * matrixes[end-1].second);
    }
    
    return cost[start][end] = minCost;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for(int i = 0; i <= N; ++i) {
        for(int j = i; j <= N; ++j) {
            cost[i][j] = -1;
        }
    }
    
    for(int i = 0; i < N; ++i) {
        cost[i][i+1] = 0;
    }
    
    for(int i = 0; i < N; ++i) {
        int r;
        int c;
        cin >> r >> c;
        matrixes[i] = make_pair(r, c);
    }
    
    cout << getMinCost(0, N) << endl;
    
    return 0;
}
