#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	
	for(int tcCnt = 0; tcCnt < T; ++tcCnt) {
		string S;
		cin >> S;
		
		int zeroCnt = 0;
		bool priorZero = false;
		
		for(int i = 0; i < S.size(); ++i) {
			if(S[i] == '0') {
				if(!priorZero) {
					zeroCnt++;
					priorZero = true;
				}
			} else {
				priorZero = false;
			}
		}
		
		if(zeroCnt < 3) {
			cout << zeroCnt << '\n';
		} else {
			cout << 2 << '\n';
		}
	}
	
	return 0;
}
