#include <iostream>

using namespace std;

typedef long long ll;

int inputs[100000];
ll seg[400001];

void update(int l, int r, int x, int v, int I = 1) {
	if(l == r) {
		seg[I] = v;
		return;
	}
	
	int m = (l + r) / 2;
	
	if(x <= m) update(l, m, x, v, I * 2);
	else update(m + 1, r, x, v, I * 2 + 1);
	
	seg[I] = seg[I * 2] + seg[I * 2 + 1];
	
	return;
}


ll query(int l, int r, int x, int y, int I = 1) {
	if(y < l || r < x) return 0;
	if(x <= l && r <= y) return seg[I];
	int m = (l + r) / 2;
	return query(l, m, x, y, I * 2) + query(m + 1, r, x, y, I * 2 + 1);
}


ll build(int l, int r, int I) {
	if(l == r) return seg[I] = inputs[l];
	int m = (l + r) / 2;
	return seg[I] = build(l, m, I * 2) + build(m + 1, r, I * 2 + 1);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, Q;
	cin >> N >> Q;
	
	for(int i = 0; i < N; ++i) {
		cin >> inputs[i];
	}
	
	build(0, N - 1, 1);
	
	for(int i = 0; i < Q; ++i) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		x--;
		y--;
		a--;
		
		if(x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		
		cout << query(0, N-1, x, y) << '\n';
		update(0, N-1, a, b);
	}
	
	return 0;
}
