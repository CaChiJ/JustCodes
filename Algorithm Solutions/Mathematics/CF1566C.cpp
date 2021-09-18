#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	
	for(int tcCnt = 0; tcCnt < T; ++tcCnt) {
		int N;
		cin >> N;
		
		int seq[N];
		
		for(int i = 0; i < N; ++i) {
			seq[i] = 0;
		}
		
		for(int col = 0; col < 2; ++col) {
			for(int i = 0; i < N; ++i) {
				int input;
				scanf("%1d", &input);
				seq[i] += input;
			}
		}
		
		int result = 0;
		
		for(int i = 0; i < N; ++i) {
			//cout << seq[i] << '\n';
			if(seq[i] == 1) {
				result += 2;
			} else if(seq[i] == 0) {
				if(i == N - 1) {
					result += 1;
					continue;
				}
				
				if(seq[i + 1] == 2) {
					result += 2;
					i++;
				} else {
					result += 1;
				}
			} else {
				if(i == N - 1) {
					continue;
				}
				
				if(seq[i + 1] == 0) {
					result += 2;
					i++;
				}
			}
		}
		
		cout << result << '\n';
	}
}
