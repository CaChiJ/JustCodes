#include <iostream>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	
	int nMin = atoi(argv[1]);
	int nMax = atoi(argv[2]);
	
	int rMin = atoi(argv[3]);
	int rMax = atoi(argv[4]);
	
	int N = rnd.next(nMin, nMax);
	printf("%d\n", N);
	
	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < N; ++c) {
			printf("%d", rnd.next(rMin, rMax));
			if (c != N - 1) printf(" ");
		}

		printf("\n");
	}
	
	return 0;
}
