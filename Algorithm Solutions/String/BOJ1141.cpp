
// Online IDE - Code Editor, Compiler, Interpreter

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int N;
    scanf("%d\n", &N);
    
    set<string> s;
    
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        s.insert(str);
    }
    
    for (auto it = s.begin(); it != s.end(); ) {
        it++;
        if (it == s.end()) {
            break;
        }
        it--;
        
        string str = *it;
        string nextStr = *(++it);
        it--;
        
        cout << str << " - " << nextStr << endl;
        
        if (str.size() > nextStr.size()) {
            it++;
            continue;
        }
        
        bool isPrefix = true;
        
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != nextStr[i]) {
                isPrefix = false;
                break;
            }
        }
        
        if (isPrefix) {
            s.erase(it++);
        } else {
            it++;
        }
    }
    
    printf("%d\n", (int) s.size());
    
    return 0;
}

