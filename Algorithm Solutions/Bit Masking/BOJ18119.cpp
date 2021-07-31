#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, M;
    cin >> N >> M;
    
    vector<unsigned int> words(N, 0);
    unsigned int brain = (1 << ('z' - 'a' + 1)) - 1;
    
    for(int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        
        for(int j = 0; j < str.size(); ++j) {
            words[i] |= 1ul << (str[j] - 'a');
        }
    }
    
    for(int i = 0; i < M; ++i) {
        int o;
        char x;
        cin >> o >> x;
        
        if(o == 1) {
        	if(x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u') {
            	brain -= 1ul << (x - 'a');
			}
        } else if(o == 2) {
            brain += 1ul << (x - 'a');
        } else {
            cout << "ERROR\n";
        }
        
        int cnt = 0;
        
        for(int i = 0; i < N; ++i) {
            if((words[i] & brain) == words[i]) {
				cnt++;
            }
        }
        
        cout << cnt << '\n';
    }

    return 0;
}
