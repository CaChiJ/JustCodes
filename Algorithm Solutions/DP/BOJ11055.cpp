#include <iostream>

using namespace std;

const int MAX_N = 1000;

int seq[MAX_N];
int table[MAX_N][2]; // 0: length, 1: maxsum

int main(void) {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
	}
	
	for (int i = 0; i < N; ++i) {
		int val = seq[i];
		int maxSum = val;
			
		for (int j = 0; j < i; ++j) {
			if (seq[j] >= val) {
				continue;
			}
			
			if (maxSum < table[j][1] + val) {
				maxSum = table[j][1] + val;
			}
		}
		
		table[i][1] = maxSum;
	}
	
	int maxSum = 0;
	
	for (int i = 0; i < N; ++i) {
		if (table[i][1] > maxSum) {
			maxSum = table[i][1];
		}
	}
	
	cout << maxSum << endl;
	
	
	return 0;
}