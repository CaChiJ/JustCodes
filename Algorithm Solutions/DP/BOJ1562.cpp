#include <iostream>
#include <cstring>

using namespace std;

const int DENOM = 1'000'000'000;

int table[101][10][1024];	// 길이가 i인 j로 시작하는 수 중에 k(mask)에서 1인 자리가 모두 있는 수의 개수

long long solution(int len, int first, int mask);
int setBit(int bits, int idx, int val);

int main(void) {
	int N;
	cin >> N;
	
	memset(table, -1, sizeof(table));
	
	long long result = 0;
	
	for (int i = 1; i <= 9; i++) {
		result = (result + solution(N, i, 1023)) % DENOM;
	}
	
	cout << result << endl;
	
	return 0;
}

long long solution(int len, int first, int mask) {
	if (table[len][first][mask] != -1) {
		return table[len][first][mask];
	}
	
	if (len == 1) {
		int newMask = setBit(mask, first, 0);
		return table[len][first][mask] = newMask == 0 ? 1 : 0;
	}
	
	long long result = 0;
	int newMask = setBit(mask, first, 0);
	
	if (first != 9) {
		result = (result + solution(len - 1, first + 1, newMask)) % DENOM;
	}
	
	if (first != 0) {
		result = (result + solution(len - 1, first - 1, newMask)) % DENOM;
	}
	
	return table[len][first][mask] = result;
}

int setBit(int bits, int idx, int val) {
	if (val == 1) {
		bits = bits | (1 << idx);
	} else if (val == 0) {
		bits = bits & ~(1 << idx);
	} else {
		cout << "error: val should be 0 or 1";
	}
	
	return bits;
}