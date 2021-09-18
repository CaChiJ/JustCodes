#include <iostream>

using namespace std;

int main(void) {
	int TC;
	cin >> TC;
	
	for(int tcCnt = 0; tcCnt < TC; ++tcCnt) {
		int N, M;
		cin >> N >> M;
		
		int result = 0;
		
		for(int i = 0; i < N; ++i) {
			
			int seq[M];
			
			for(int j = 0; j < M; ++j) {
				cin >> seq[j];
				
				for(int k = 0; k < j; ++k) {
					
					if(seq[k] < seq[j]) {
						result++;
					}
				}
			}
		}
		
		cout << result << '\n';
	}
	
	return 0;
}
