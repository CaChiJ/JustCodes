#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> weight(N);
    vector<int> value(N);
    vector<int> DP(K+1, 0);
    
    for(int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
    }
    
    for(int k = 0; k < N; ++k) {
        for(int w = K; w >= weight[k]; --w) {
            DP[w] = max(DP[w], DP[w-weight[k]] + value[k]);
        }
    }
    
    cout << DP[K] << endl;
    
    return 0;
}
