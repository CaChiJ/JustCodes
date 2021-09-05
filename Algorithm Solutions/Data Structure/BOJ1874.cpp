#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    stack<int> stk;
    stk.push(0);
    
    int count = 0;
    string result = "";
    
    for(int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        
        if(stk.top() < input) {
            while(stk.top() < input) {
                count++;
                stk.push(count);
                result += "+\n";
            }
            
            result += "-\n";
            stk.pop();
        } else if(stk.top() == input) {
            result += "-\n";
            stk.pop();
        } else {
            result = "NO";
            break;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
