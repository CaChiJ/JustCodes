#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    while(true) {
        string str;
        getline(cin, str);
        
        if(str == ".") {
            break;
        }
        
        stack<char> stk;
        bool isBalanced = true;
        
        for(auto i = str.begin(); i < str.end(); ++i) {
        	if(*i == '(' || *i == '[') {
        		stk.push(*i);
			} else if(*i == ')' || *i == ']') {
				if(stk.empty()) {
					isBalanced = false;
					break;	
				} else if(stk.top() =='(' && *i == ')' || stk.top() == '[' && *i == ']') {
					stk.pop();
				} else if(stk.top() == '(' && *i == ']' || stk.top() == '[' && *i == ')') {
                	isBalanced = false; 
                	break;
				}
            }
        }
        
        if(!stk.empty()) {
        	isBalanced = false;
		}
        
        if(isBalanced) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
