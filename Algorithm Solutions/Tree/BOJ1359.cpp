#include <iostream>
#include <utility>

using namespace std;

pair<int, bool> seg[400'000];

int update(int l, int r, int x, int y, int I = 1) {
	if(y < l || r < x) return 0;
	if(x <= l && r <= y) return seg[I].second = !seg[I].second;
	int m = (l + r) / 2;
	update(l, m, x, y, I * 2);
	update(m + 1, r, x, y, I * 2 + 1);
	
	seg[I].first = 0;
	
	if(seg[I * 2].second) {
		seg[I].first += m - l + 1 - seg[I * 2].first;
	} else {
		seg[I].first += seg[I * 2].first;
	}
	
	if(seg[I * 2 + 1].second) {
		seg[I].first += r - (m + 1) + 1 - seg[I * 2 + 1].first;
	} else {
		seg[I].first += seg[I * 2 + 1].first;
	}
	
	return seg[I].first;
}


int query(int l, int r, int x, int y, int I = 1) {
	if(y < l || r < x) return 0;
	if(x <= l && r <= y) {
		if(seg[I].second) {
			return r - l + 1 - seg[I].first;
		} else {
			return seg[I].first;
		}
	}
	
	if(seg[I].second) {
		seg[I].second = false;
		seg[I].first = r - l + 1 - seg[I].first;
		seg[I * 2].second = !seg[I * 2].second;
		seg[I * 2 + 1].second = !seg[I * 2 + 1].second;
	}
	
	int m = (l + r) / 2;
	return query(l, m, x, y, I * 2) + query(m + 1, r, x, y, I * 2 + 1);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < M; ++i) {
        int O, S, T;
        cin >> O >> S >> T;
        S--;
        T--;
        
        if(O == 0) {
            update(0, N - 1, S, T);
        } else {
            cout << query(0, N - 1, S, T) << '\n';
        }
    }
    
    return 0;
}
