#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int T;
    cin >> T;
    
    for(int tcCnt = 0; tcCnt < T; ++tcCnt) {
        string p;
        cin >> p;
        
        int n;
        cin >> n;
        
        deque<int> dq;
        string temp = "";
        
        char trash;
        do {
            cin >> trash;
        } while(trash != '[');
        
        while(true) {
            char input;
            cin >> input;
            
            if('0' <= input && input <= '9') {
                temp += input;
                continue;
            }
            
            if(temp != "") {
            	dq.push_back(atoi(temp.c_str()));
            	temp = "";
			}
            
            if(input == ']') {
                break;
            }
        }
        
        bool isReversed = false;
        bool isError = false;
        
        for(auto op = p.begin(); op < p.end(); ++op) {
            if(*op == 'R') {
                isReversed = !isReversed;
            } else if(*op == 'D') {
                if(dq.empty()) {
                    isError = true;
                    break;
                }
                
                if(isReversed) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            } else {
                isError = true;
                break;
            }
        }
        
        if(isError) {
            cout << "error\n";
            continue;
        }
        
        cout << '[';
        
        if(!isReversed) {
            for(auto iter = dq.begin(); iter < dq.end(); ++iter) {
                cout << *iter;
                
                if(iter != dq.end() - 1) {
                    cout << ',';
                }
            }
        } else {
            for(auto iter = dq.rbegin(); iter < dq.rend(); ++iter) {
                cout << *iter;
                
                if(iter != dq.rend() - 1) {
                    cout << ',';
                }
            }
        }
        
        cout << "]\n";
    }
    
    return 0;
}
