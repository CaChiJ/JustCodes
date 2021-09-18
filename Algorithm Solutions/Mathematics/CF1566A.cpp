#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	
	for(int tcCnt = 0; tcCnt < T; ++tcCnt) {
		int N, S;
		cin >> N >> S;
		
		cout << S / (N / 2 + 1) << '\n';
	}
	
	return 0;
}
