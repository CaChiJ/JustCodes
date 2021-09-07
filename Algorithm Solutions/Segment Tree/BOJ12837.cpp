#include <iostream>

using namespace std;

typedef long long ll;

int inputs[1'000'000];
ll seg[4'000'000];


ll update(int l, int r, int x, int v, int I = 1) {
    if(x < l || r < x) return seg[I];
    if(l == r) return seg[I] += v;
    int m = (l + r) / 2;
    return seg[I] = update(l, m, x, v, I * 2) + update(m + 1, r, x, v, I * 2 + 1);
}


ll query(int l, int r, int x, int y, int I = 1) {
    if(y < l || r < x) return 0;
    if(x <= l && r <= y) return seg[I];
    int m = (l + r) / 2;
    return query(l, m, x, y, I * 2) + query(m + 1, r, x, y, I * 2 + 1);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    for(int i = 0; i < Q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if(a == 1) {
        	b--;
            update(0, N - 1, b, c);
        } else {
        	b--;
        	c--;
            cout << query(0, N - 1, b, c) << '\n';
        }
    }
    
    return 0;
}
