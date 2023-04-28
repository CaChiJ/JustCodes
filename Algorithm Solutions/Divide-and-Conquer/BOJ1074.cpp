#include <iostream>
#include <cmath>

using namespace std;

long long solution(int, int, int);

int main(void) {
	int N, R, C;
	cin >> N >> R >> C;
	
	cout << solution(N, R + 1, C + 1) << endl;
	
	return 0;
}

long long solution(int n, int r, int c) {
	if (n == 1) {
		return (r == 2) * 2 + (c == 2);
	}
	
	int len = (int) pow(2, n);
	int half = len / 2;
	int order = (r > half) * 2 + (c > half);
	
	long long result = order * half * half;
	result += solution(
		n - 1,
		r > half ? r - half : r,
		c > half ? c - half : c
	);
	
	return result;
}