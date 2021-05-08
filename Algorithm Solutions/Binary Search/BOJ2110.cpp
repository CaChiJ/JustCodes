#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200000;
int X[MAXN];

int main(void)
{
	int N, C;
	cin>>N>>C;
	
	for(int i = 0; i < N; ++i) {
		cin>>X[i];
	}
	
	sort(X, X + N);
	
	int left = 0;
	int right = X[N-1] - X[0];
	
	while(left < right)
	{
		int mid = (left + right) / 2.0 + 0.5;
		int dist = 987654321;
		int count = 0;
		
		for(int i = 0; i < N; ++i) {
			if(i > 0) {
				dist += X[i] - X[i-1];
			}
			
			if(dist >= mid) {
				count++;
				dist = 0;
			} 
			
			if(count > C) {
				break;
			}
		}
		
		if(count >= C) {
			left = mid;
		} else {
			right = mid - 1;
		}
	}
	
	cout<<left<<endl;
	
	return 0;
}
