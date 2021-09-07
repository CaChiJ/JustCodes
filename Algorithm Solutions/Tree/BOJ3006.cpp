#include <iostream>

using namespace std;

int idxOf[100'000];
int seg[400'000];

int update(int l, int r, int x, int v, int I = 1) {
    if(x < l || r < x) return seg[I];
    if(l == r) return seg[I] = v;
    int m = (l + r) / 2;
    return seg[I] = update(l, m, x, v, I * 2) + update(m + 1, r, x, v, I * 2 + 1);
}


int query(int l, int r, int x, int y, int I = 1) {
    if(y < l || r < x) return 0;
    if(x <= l && r <= y) return seg[I];
    int m = (l + r) / 2;
    return query(l, m, x, y, I * 2) + query(m + 1, r, x, y, I * 2 + 1);
}


int build(int l, int r, int I = 1) {
    if(l == r) return seg[I] = 1;
    int m = (l + r) / 2;
    return seg[I] = build(l, m, I * 2) + build(m + 1, r, I * 2 + 1);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        input--;
        idxOf[input] = i;
    }
    
    build(0, N - 1);
    
    for(int i = 1; i <= N; ++i) {
        if(i % 2 == 1) {
            int v = (i - 1) / 2;
            cout << query(0, N - 1, 0, idxOf[v] - 1) << '\n';
            update(0, N - 1, idxOf[v], 0);
        } else { 
            int v = N - 1 - (i - 1) / 2;
            cout << query(0, N - 1, idxOf[v] + 1, N - 1) << '\n';
            update(0, N - 1, idxOf[v], 0);
        }
    }
    
    return 0;
}
