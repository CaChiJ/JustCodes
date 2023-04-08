#include <iostream>
#include <algorithm>

using namespace std;

struct dot {
	long long int x;
	long long int y;
	long long int z;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M;
	dot dots[100000];
	
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		cin >> dots[i].x >> dots[i].y >> dots[i].z;
	}
	
	cin >> M;
	
	for (int i = 0; i < M; ++i) {
		long long x, y, z, r;
		cin >> x >> y >> z >> r;
		
		int count = 0;
		
		for (int dotIdx = 0; dotIdx < N; ++dotIdx) {
			int x1= dots[dotIdx].x;
			int y1= dots[dotIdx].y;
			int z1= dots[dotIdx].z;
			
			long long dx = x - x1;
			long long dy = y - y1;
			long long dz = z - z1;
			
			if (dx*dx + dy*dy + dz*dz <= r*r) {
				count++;
			}
		}
		
		cout << count << '\n';
	}
	
	return 0;
}
