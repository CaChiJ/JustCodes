#include <iostream>

using namespace std;

int main(void) {
	int N, F;
	cin >> N >> F;
	
    int N2 = N - N % 100;
	
	for (int i = 0; i < 100; ++i) {
		int N3 = N2 + i;
		
		if (N3 % F == 0) {
			printf("%02d", i);
			return 0;
		}
	}
	
	return 0;
}