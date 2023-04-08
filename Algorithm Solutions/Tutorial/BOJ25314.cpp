#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	
	int longCount = N / 4;
	
	for (int i = 0; i < longCount; ++i) {
		printf("long ");
	}
	
	printf("int");
	
	return 0;
}