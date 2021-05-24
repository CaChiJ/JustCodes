#include <iostream>
#include <vector>

using namespace std;
  
const int MAX_N = 20;
const int MAX_HEALTH = 100;
int DP[MAX_N + 1][MAX_HEALTH + 1];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> L(N);
    vector<int> J(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> L[i];
    }
    
    for(int i = 0; i < N; ++i) {
        cin >> J[i];
    }
    
    for(int k = 0; k < N; ++k) {
        for(int w = 1; w < MAX_HEALTH; ++w) {
            if(w >= L[k]) {
                DP[k+1][w] = max(DP[k][w], DP[k][w - L[k]] + J[k]);
            } else {
                DP[k+1][w] = DP[k][w];
            }
        }
    }
    
    cout << DP[N][99] << endl;
    
    return 0;
}
