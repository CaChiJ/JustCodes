#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K;
	cin >> K;
	
	int stack[K];
	int size = 0;
	int sum = 0;
	
	for(int k = 0; k < K; ++k) {
		int n;
		cin >> n;
		
		if(n == 0) {
			size--;
			sum -= stack[size];
		} else {
			stack[size] = n;
			sum+= n;
			size++;	
		}
	}
	
	cout << sum << '\n';
	
	return 0;
}
