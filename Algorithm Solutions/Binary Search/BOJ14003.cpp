#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N;
    cin >> N;
    
    int seq[N];
    vector<int> DP;
    int size = 0;
    int hist[N];
    
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
        auto lb = lower_bound(DP.begin(), DP.end(), seq[i]);
        hist[i] = lb - DP.begin();
        if(lb == DP.end()) {
        	DP.push_back(seq[i]);
		} else {
			*lb = seq[i];
		}
    }
    
    cout << DP.size() << endl;
    
    stack<int> stk;
    int last = DP.size() - 1;
    
    for(int i = N - 1; i >= 0; --i) {
        if(hist[i] == last) {
            last--;
            stk.push(seq[i]);
        }
    }
    
    while(!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    
    return 0;
}
