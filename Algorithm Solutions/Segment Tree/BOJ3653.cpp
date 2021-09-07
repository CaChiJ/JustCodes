#include <iostream>

using namespace std;

int idxOf[100'000];
int seg[800'000];


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


int init(int l, int r, int lastIdx, int I = 1) {
    if(l == r) {
    	if(l <= lastIdx) return seg[I] = 1;
		else return seg[I] = 0;
	}
    int m = (l + r) / 2;
    return seg[I] = init(l, m, lastIdx, I * 2) + init(m + 1, r, lastIdx, I * 2 + 1);
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    
    for(int tcCnt = 0; tcCnt < TC; ++tcCnt) {
        int N, M;
        cin >> N >> M;
        
        int lastIdx = N - 1;
        init(0, N + M - 1, lastIdx);
        
        for(int i = 0; i < N; ++i) {
            idxOf[i] = N - 1 - i;
        }
        
        for(int i = 0; i < M; ++i) {
            int movie;
            cin >> movie;
            movie--;
            
            cout << query(0, N + M - 1, idxOf[movie] + 1, N + M - 1) << ' ';
            
            if(lastIdx != idxOf[movie]) {
            	update(0, N + M - 1, idxOf[movie], 0);
            	lastIdx++;
            	idxOf[movie] = lastIdx;
            	update(0, N + M - 1, idxOf[movie], 1);
			}
        }
        
        cout << '\n';
    }
    
    return 0;
}                                               
