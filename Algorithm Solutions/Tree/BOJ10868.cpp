#include <iostream>
#include <climits>

using namespace std;

int inputs[100'000];
int seg[400'000];
int N, M;


int query(int l, int r, int x, int y, int I = 1) {
    if(y < l || r < x) return INT_MAX;
    if(x <= l && r <= y) return seg[I];
    int m = (l + r) / 2;
    return min(query(l, m, x, y, I * 2), query(m + 1, r, x, y, I * 2 + 1));
}


int build(int l, int r, int I = 1) {
    if(l == r) {
    	if(l < N) return seg[I] = inputs[l];
    	else return seg[I] = INT_MAX;
	}
    int m = (l + r) / 2;
    return seg[I] = min(build(l, m, I * 2), build(m + 1, r, I * 2 + 1));
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i) {
        cin >> inputs[i];
    }
    
    build(0, N - 1);
    
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(0, N - 1, a, b) << '\n';
    }
    
    return 0;
}
