#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	
	if (N % 2 == 0) {
		cout << "CY";
	} else {
		cout << "SK";
	}
	
	return 0;
}

/*
1: SK
2: CY
3: SK
4: CY
5: SK
6: CY
7: SK
8: CY

*/