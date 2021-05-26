#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, goal;
    cin >> N >> goal;
    
    vector<int> coins(N);
    vector<int> DP(goal+1, -1);
    DP[0] = 0;
    
    for(int i = 0; i < N; ++i) {
        cin >> coins[i];
    }
    
    for(int k = 0; k < N; ++k) {
        for(int w = coins[k]; w <= goal; ++w) {
        	if(DP[w-coins[k]] >= 0) {
        		if(DP[w] == -1) {
        			DP[w] = DP[w-coins[k]] + 1;	
				} else {
            		DP[w] = min(DP[w], DP[w-coins[k]] + 1);
				}
			}
        }
    }
    
    cout << DP[goal] << endl;
    
    return 0;
}
