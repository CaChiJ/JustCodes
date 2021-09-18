#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int pos[200'001];
int DP[200'001];

int getMinDist(int a, int N) {
	if(a > 2 * N) {
		return INT_MAX;
	}
	
	if(DP[a] != -1) {
		return DP[a];
	}
	
	return DP[a] = min(pos[a + 1], getMinDist(a + 2, N));
}

int main(void) {
	int TC;
	cin >> TC;
	
	for(int tcCnt = 0; tcCnt < TC; ++tcCnt) {
		int N;
		cin >> N;
		
		for(int i = 0; i <= 2 * N; ++i) {
			DP[i] = -1;
		}
		
		for(int i = 0; i < N; ++i) {
			int input;
			cin >> input;
			pos[input] = i;
		}
		
		for(int i = 0; i < N; ++i) {
			int input;
			cin >> input;
			pos[input] = i;
		}
		
		int result = INT_MAX;
		
		for(int i = 1; i <= N; ++i) {
			result = min(result, getMinDist(i * 2 - 1, N) + pos[i * 2 - 1]);
		}
		
		cout << result << '\n';
	}
	
	return 0;
}
