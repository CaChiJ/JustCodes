#include <iostream>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	
	int basket[101];
	
	for (int i = 0; i <= N; ++i) {
		basket[i] = i;
	}
	
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		
		int tmp = basket[a];
		basket[a] = basket[b];
		basket[b] = tmp;
	}
	
	for (int i = 1; i <= N; ++i) {
		cout << basket[i] << ' ';
	}
	
	return 0;
}