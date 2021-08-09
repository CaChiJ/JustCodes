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
    
    vector<int> wire(500000, -1);
    vector<int> pos(500000, -1);
    
    for(int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        wire[start - 1] = end - 1;
    }
    
    vector<int> answer;
    
    for(int i = 0; i < 500000; ++i) {
        if(wire[i] == -1) {
            continue;
        }
        
        auto lb = lower_bound(answer.begin(), answer.end(), wire[i]);
        
        pos[i] = lb - answer.begin();
        //cout << i + 1 << ' ' << pos[i] <<'\n';
        
        if(lb == answer.end()) {
            answer.push_back(wire[i]);
        } else {
            *lb = wire[i];
        }
    }
    
    cout << N - answer.size() << endl;
    
    int now = answer.size() - 1;
    stack<int> stk;
    
    for(int i = 499999; i >= 0; i--) {
    	if(now == pos[i]) {
    		now--;
		} else if(pos[i] != -1) {
    		stk.push(i);
		}
	}
	
	while(!stk.empty()) {
		cout << stk.top() + 1 << '\n';
		stk.pop();
	}
    
    return 0;
}
