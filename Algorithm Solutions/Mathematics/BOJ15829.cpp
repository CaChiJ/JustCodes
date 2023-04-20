#include <iostream>

using namespace std;

const int r = 31;
const int denom = 1234567891;

int main(void) {
	int L;
	cin >> L;
	
	char str[51];
	scanf("%s", str);
	
	long long hash = 0;
	
	for (int i = L - 1; i >= 0; --i) {
		int v = str[i] - 'a' + 1;
		hash = (hash * r + v) % denom;
	}
	
	cout << hash << endl;

	return 0;
}