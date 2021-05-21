#include <iostream>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    
    int left = 1;
    int right = K;
    int ret = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int lessCount = 0;
        int sameCount = 0;
        
        for(int i = 1; i <= N; ++i) {
			lessCount += min(N, mid / i);
        }
        
        if(lessCount < K) {
            left = mid+1;
        } else if(lessCount >= K) {
        	ret = mid;
            right = mid-1;
    	}
    }
    
    cout << ret << endl;
    
    return 0;
}
