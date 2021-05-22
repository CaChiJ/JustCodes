#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> T;
    for(int i = 0; i < N; ++i) {
        int tmpT;
        cin >> tmpT;
        T.push_back(tmpT);
    }
    
    long long left = 0;
    long long right = (M / N + 1) * 1e9;
    while(left < right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for(int i = 0; i < N; ++i) {
            cnt += mid / T[i];
        }
        
        if(cnt >= M) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    
    return 0;
}
