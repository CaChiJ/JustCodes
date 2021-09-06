#include <iostream>

using namespace std;

typedef long long ll;

ll numbers[1000000];
ll seg[1 << 21];

void update(int x, ll v, int l, int r, int I = 1) {
	if(l == r) {
		seg[I] = v;
		return;
	}
	
	int m = (l + r) / 2;
	
	if(x <= m) update(x, v, l, m, I * 2);
	else update(x, v, m+1, r, I * 2 + 1);
	
	seg[I] = seg[I * 2] + seg[I * 2 + 1];
	
	return;
}


ll query(int x, int y, int l, int r, int I = 1) {
	if (y < l || r < x) return 0;
	if (x <= l && r <= y) return seg[I];
	int m = (l + r) / 2;
	return query(x, y, l, m, I * 2) + query(x, y, m + 1, r, I * 2 + 1);
}


ll build(int l, int r, int I) {
	if(l == r) return seg[I] = numbers[l];
	int m = (l + r) / 2;
	return seg[I] = build(l, m, I * 2) + build(m + 1, r, I * 2 + 1);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, K;
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; ++i) {
		cin >> numbers[i];
	}
	
	build(0, N-1, 1);
	
	for(int i = 0; i < M + K; ++i) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		
		if(a == 1) {
			update(b-1, c, 0, N-1);
		} else {
			cout << query(b-1, c-1, 0, N-1) << '\n';
		}
	}
	
	return 0;
}
