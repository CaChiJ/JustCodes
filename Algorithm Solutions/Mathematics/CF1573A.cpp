#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int TC;
	scanf("%d", &TC);
	
	for(int tcCnt = 0; tcCnt < TC; ++tcCnt) {
		int N;
		scanf("%d", &N);
		
		int clocks[N];
		
		for(int i = 0; i < N; ++i) {
			scanf("%1d", clocks+i);
		}
		
		int result = 0;
		
		for(int i = 0; i < N - 1; ++i) {
			if(clocks[i] != 0) {
				result++;
			}
			
			result += clocks[i];
		}
		
		result += clocks[N-1];
		
		cout << result << '\n';
	}
	
	return 0;
}
