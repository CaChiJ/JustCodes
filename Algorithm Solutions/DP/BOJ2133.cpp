#include <iostream>

using namespace std;

int table[31];

int main(void) {
	int N;
	cin >> N;
	
	table[0] = 1;
	
	for (int i = 2; i <= N; ++i) {
		table[i] = table[i - 2] * 3;
		
		for (int j = 0; j < i; ++j) {
			if ((i - j) % 2 != 0 || (i - j) < 4) {
				continue;
			}
			
			table[i] += table[j] * 2;
		}
	}
	
	cout << table[N] << endl;
	
	return 0;
}