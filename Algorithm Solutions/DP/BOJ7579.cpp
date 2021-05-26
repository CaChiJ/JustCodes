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
    
    vector<int> m(N);
    vector<int> c(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> m[i];
    }
    
    for(int i = 0; i < N; ++i) {
        cin >> c[i];
    }
    
    vector<int> DP(M+1, -1);
    DP[0] = 0;
    
    for(int app = 0; app < N; ++app) {
    	for(int i = max(0, M-m[app]+1); i <= M; ++i) {
    		if(DP[i] == -1) {
    			continue;
			}
			
			if(DP[M] == -1) {
				DP[M] = DP[i] + c[app];
			} else {
				DP[M] = min(DP[M], DP[i] + c[app]);
			}
		}
		
        for(int left = M; left >= m[app]; --left) {
            if(DP[left - m[app]] == -1) {
                continue;
            }
            
            if(DP[left] == -1) {
                DP[left] = DP[left - m[app]] + c[app];
            } else {
                DP[left] = min(DP[left], DP[left - m[app]] + c[app]);
            }
        }
    }
    
    cout << DP[M] << endl;;
    
    return 0;
}
