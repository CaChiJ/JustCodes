#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N;
    cin >> N;
    
    vector<int> inputs(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> inputs[i];
    }
    
    int result = 2000000031;
    int lastLeft = 0;
    int lastRight = N - 1;
    int left = 0;
    int right = N - 1;
    
    while(left < right) {
        int newSum = inputs[left] + inputs[right];
        
        if(abs(newSum) < result) {
            lastRight = right;
            lastLeft = left;
            result = abs(newSum);
        }
        
        if(newSum > 0) {
            right--;
        } else {
            left++;
        }
    }
    
    cout << inputs[lastLeft] << ' ' << inputs[lastRight] << '\n';
    return 0;
}
