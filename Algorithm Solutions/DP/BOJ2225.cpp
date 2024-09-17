#include <iostream>

using namespace std;

int table[201][201];

int main(void) {
	int N, K;
	cin >> N >> K;
	
	for (int i = 0; i <= N; ++i) {
		table[1][i] = 1;
	}
	
	for (int i = 0; i <= K; ++i) {
		table[i][0] = 1;
	}
	
	for (int k = 2; k <= K; ++k) {
		
		for (int i = 1; i <= N; ++i) {
			table[k][i] = (table[k][i-1] + table[k-1][i]) % 1'000'000'000;
		}
	}
	
	// for (int i = 0; i <= K; ++i) {
	// 	for (int j = 0; j <= N; ++j) {
	// 		printf("k: %d | n: %d => %d\n", i, j, table[i][j]);
	// 	}
	// }
	
	cout << table[K][N] << endl;
	
	return 0;
}

/*
N K => Result
0 1 => 1
1 1 => 1
2 1 => 1
3 1 => 1

0 2 => 1
1 2 => 2
2 2 => 3
3 2 => 4
4 2 => 5
5 2 => 6

1 3 => 3
2 3 => 6
(1, 1, 0) (0, 1, 1) (1, 0, 1) (2, 0, 0), (0, 2, 0), (0, 0, 2)

*/