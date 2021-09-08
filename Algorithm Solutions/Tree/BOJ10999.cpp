#include <iostream>
#include <utility>

using namespace std;

typedef long long ll;

ll inputs[1'000'000];
pair<ll, ll> seg[4'000'000];
int N, M, K;


ll update(int l, int r, int x, int y, int v, int I = 1) {
    if(y < l || r < x) return 0;
    if(x <= l && r <= y) return seg[I].second += v;
    int m = (l + r) / 2;
    update(l, m, x, y, v, I * 2);
    update(m + 1, r, x, y, v, I * 2 + 1);
    return seg[I].first = (seg[I * 2].first + seg[I * 2].second * (m - l + 1)) + (seg[I * 2 + 1].first + seg[I * 2 + 1].second * (r - m));
}


ll query(int l, int r, int x, int y, int I = 1) {
    if(y < l || r < x) return 0;
    if(x <= l && r <= y) return seg[I].first + seg[I].second * (r - l + 1);
    
    if(seg[I].second != 0) {
        seg[I * 2].second += seg[I].second;
        seg[I * 2 + 1].second += seg[I].second;
        seg[I].first += seg[I].second * (r - l + 1);
        seg[I].second = 0;
    }
    
    int m = (l + r) / 2;
    return query(l, m, x, y, I * 2) + query(m + 1, r, x, y, I * 2 + 1);
}


ll build(int l, int r, int I = 1) {
    if(l == r) {
    	seg[I] = {inputs[l], 0};
    	return seg[I].first;	
	}
    int m = (l + r) / 2;
    return seg[I].first = build(l, m, I * 2) + build(m + 1, r, I * 2 + 1);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    // jeonseon jonna jon jal ssibal choi hyun jun byung sin
    for(int i = 0; i < N; ++i) {
        cin >> inputs[i];
    }
    
    build(0, N - 1);
    
    for(int i = 0; i < M + K; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        b--;
        c--;
        
        if(a == 1) {
            ll d;
            cin >> d;
            update(0, N - 1, b, c, d);
        } else {
            cout << query(0, N - 1, b, c) << '\n';
        }
    }
    
    return 0;
}
