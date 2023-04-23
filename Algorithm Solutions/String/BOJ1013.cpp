#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	
	char stateMap[26][2];
	
	stateMap['s' - 'a'][0] = 'a';
	stateMap['s' - 'a'][1] = 'b';
	
	stateMap['a' - 'a'][0] = 'f';
	stateMap['a' - 'a'][1] = 's';
	
	stateMap['b' - 'a'][0] = 'c';
	stateMap['b' - 'a'][1] = 'f';
	
	stateMap['c' - 'a'][0] = 'd';
	stateMap['c' - 'a'][1] = 'f';
	
	stateMap['d' - 'a'][0] = 'd';
	stateMap['d' - 'a'][1] = 'e';
	
	stateMap['e' - 'a'][0] = 'a';
	stateMap['e' - 'a'][1] = 'g';
	
	stateMap['g' - 'a'][0] = 'h';
	stateMap['g' - 'a'][1] = 'g';
	
	stateMap['h' - 'a'][0] = 'd';
	stateMap['h' - 'a'][1] = 's';
	
	for (int tcCnt = 0; tcCnt < T; ++tcCnt) {
		char inp[201];		
		int len = 0;
		
		cin >> inp;
		
		while (inp[len] != '\0') {
			len++;
		}
		
		char state = 's';
		
		for (int i = 0; i < len; ++i) {
			int v = inp[i] == '1' ? 1 : 0; 
			char newState = stateMap[state - 'a'][v];
			
			state = newState;
			
			if (newState == 'f') {	
				break;
			}
		}
		
		if (state == 's' || state == 'e' || state == 'g') {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}