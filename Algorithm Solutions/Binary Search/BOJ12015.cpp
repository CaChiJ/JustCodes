#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<int> table;
    for(int i = 0; i < N; ++i) {
        int left = 0;
        int right = table.size();
        
        while(left < right) {
            int mid = (left + right) / 2;
            if(table[mid] < A[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if(left == table.size()) {
            table.push_back(A[i]);
        } else {
            table[left] = A[i];
        }
    }
    
    cout << table.size() << endl;
    
    return 0;
}
