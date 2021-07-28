#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> DP[503][503];

pair<int, int> getMinCost(vector<int>& files, int start, int end) {
    if(DP[start][end].first != -1) {
        return DP[start][end];
    }
    
    if(start == end-1) {
        return DP[start][end] = make_pair(files[start], 0);
    }
    
    pair<int, int> minCost = make_pair(987654321, 987654321);
    
    for(int i = start+1; i < end; ++i) {
    	pair<int, int> subResult1 = getMinCost(files, start, i);
    	pair<int, int> subResult2 = getMinCost(files, i, end);
    	pair<int, int> tmp;
    	tmp.first = subResult1.first + subResult2.first;
		tmp.second = subResult1.second + subResult2.second + tmp.first;
		if(minCost.second > tmp.second) {
			minCost = tmp;
		}
    }
    
    return DP[start][end] = minCost;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int T;
    cin >> T;
    
    for(int tcCnt = 0; tcCnt < T; ++tcCnt) {
        int K;
        cin >> K;
        
        for(int i = 0; i < 503; ++i) {
        	for(int j = 0; j < 503; ++j) {
        		DP[i][j] = make_pair(-1, -1);
			}
		}
        
        vector<int> files(K);
        
        for(int i = 0; i < K; ++i) {
            cin >> files[i];
        }
        
        cout << getMinCost(files, 0, K).second << '\n';
    }
    
    return 0;
}
