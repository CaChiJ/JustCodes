#include <iostream>

using namespace std;

typedef long long ll;

int nums[1000000];
ll seg[4000000];
int mod = 1000000007;

ll update(int l, int r, int x, int v, int I = 1) {
	if(x < l || r < x) return seg[I];
	if(l == r) return seg[I] = v;
	int m = (l + r) / 2;
	return seg[I] = (update(l, m, x, v, I * 2) * update(m + 1, r, x, v, I * 2 + 1)) % mod;
}


ll query(int l, int r, int x, int y, int I = 1) {
	if(y < l || x > r) return 1;
	if(x <= l && r <= y) return seg[I];
	int m = (l + r) / 2;
	return (query(l, m, x, y, I * 2) * query(m + 1, r, x, y, I * 2 + 1)) % mod;
}


ll build(int l, int r, int I = 1) {
	if(l == r) return seg[I] = nums[l];
	int m = (l + r) / 2;
	return seg[I] = (build(l, m, I * 2) * build(m + 1, r, I * 2 + 1)) % mod;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, K;
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	
	build(0, N-1);
	
	for(int i = 0; i < M + K; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if(a == 1) {
			b--;
			update(0, N-1, b, c);
		} else {
			b--;
			c--;
			
			if(b > c) {
				int tmp = b;
				b = c;
				c = tmp;
			}
			
			cout << query(0, N-1, b, c) << '\n';
		}
	}
	
	return 0;
}
