#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> table;
    int size = 0;
    
    for(int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        
        int left = 0;
        int right = size;
        while(left < right) {
            int mid = (left + right) / 2;
            
            if(input > table[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
    	}
    	
    	if(left == size) {
    		table.push_back(input);
        	size++;
		} else if(input < table[left]) {
     		table[left] = input;
		}
    }
    
    cout << N - size << endl;
    return 0;
}
