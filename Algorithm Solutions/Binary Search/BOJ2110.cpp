#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 200'000;
int positions[MAX_N];

int main(void) {
	int N, C;
	cin >> N >> C;
	
	for (int i = 0; i < N; ++i) {
		cin >> positions[i];
	}
	
	sort(positions, positions + N);
	
	int minD = 1;
	int maxD = 1'000'000'000;
	
	while (minD < maxD) {
		int midD = (minD + maxD + 1) / 2;
		int last = positions[0];
		int count = 1;
		
		for (int i = 1; i < N; ++i) {
			int pos = positions[i];
			
			if (pos - last >= midD) {
				count++;
				last = pos;
			}
		}
		
		if (count >= C) {
			minD = midD;
		} else {
			maxD = midD - 1;
		}
	}
	
	cout << minD << endl;
	return 0;
}