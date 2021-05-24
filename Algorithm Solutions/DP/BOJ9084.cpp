#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    
    for(int tcCnt = 0; tcCnt < TC; ++tcCnt) {
        int N;
        cin >> N;
        
        vector<int> coins(N);
        
        for(int i = 0; i < N; ++i) {
            cin >> coins[i];
        }
        
        int M;
        cin >> M;
        
        int DP[M+1];
        DP[0] = 1;
        for(int i = 1; i <= M; ++i) {
            DP[i] = 0;
        }
        
        for(int k = 0; k < N; ++k) {
            for(int w = coins[k]; w <= M; ++w) {
                DP[w] = DP[w] + DP[w-coins[k]];
            }
        }
        
        cout << DP[M] << endl;
    }
    
    return 0;
}
