#include <iostream>
#include <cstring>

using namespace std;

int buckets[100];

int main(void) {
	int N, M;
	
	memset(buckets, 0, sizeof(buckets));
	
	cin >> N >> M;
	
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		
		for (int j = a; j <= b; ++j) {
			buckets[j - 1] = c;
		}
	
		// for (int i = 0; i < N; ++i) {
		// 	cout << buckets[i] + 1 << ' ';
		// }
		
		// cout << '\n';
	}
	
	for (int i = 0; i < N; ++i) {
		cout << buckets[i] << ' ';
	}
	
	return 0;
}