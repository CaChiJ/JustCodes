#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, S;
    cin >> N >> S;
    
    int pSum[N + 1];
    pSum[0] = 0;
    cin >> pSum[1];
    
    for(int i = 2; i <= N; ++i) {
        int input;
        cin >> input;
        pSum[i] = pSum[i-1] + input;
    }
    
    int minLen = INT_MAX;
    
    int left = 0;
    int right = 1;
    
    while(left < N) {
        if(right == N) {
            if(pSum[right] - pSum[left] >= S && right - left < minLen) {
                minLen = right - left;
            }
            
            left++;
        } else {
            if(pSum[right] - pSum[left] >= S) {
                if(right - left < minLen) {
                    minLen = right - left;
                }
                
                left++;
            } else {
                right++;
            }
        }
    }
    
    cout << (minLen == INT_MAX ? 0 : minLen) << endl;
    
    return 0;
}