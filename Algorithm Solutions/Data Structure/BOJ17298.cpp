#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int result[1000000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N;
    cin >> N;
    
    stack<pair<int, int> > stk;
    
    for(int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        
        while(!stk.empty() && input > stk.top().second) {
            result[stk.top().first] = input;
            stk.pop();
        }
        
        stk.push({i, input});
    }
    
    while(!stk.empty()) {
        result[stk.top().first] = -1;
        stk.pop();
    }
    
    for(int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }
    
    return 0;
}
