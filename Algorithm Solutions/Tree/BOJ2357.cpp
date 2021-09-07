#include <iostream>
#include <utility>
#include <climits>

using namespace std;

int inputs[100'000];
int minSeg[400'000];
int maxSeg[400'000];


pair<int, int> query(int l, int r, int x, int y, int I = 1) {
    if(y < l || r < x) return {INT_MAX, -1};
    if(x <= l && r <= y) return {minSeg[I], maxSeg[I]};
    int m = (l + r) / 2;
    pair<int, int> sub1 = query(l, m, x, y, I * 2);
    pair<int, int> sub2 = query(m + 1, r, x, y, I * 2 + 1);
    return {min(sub1.first, sub2.first), max(sub1.second, sub2.second)};
}


pair<int, int> build(int l, int r, int I = 1) {
    if(l == r) return {minSeg[I] = inputs[l], maxSeg[I] = inputs[l]};
    int m = (l + r) / 2;
    pair<int, int> sub1 = build(l, m, I * 2);
    pair<int, int> sub2 = build(m + 1, r, I * 2 + 1);
    return {minSeg[I] = min(sub1.first, sub2.first), maxSeg[I] = max(sub1.second, sub2.second)};
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
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
        
        pair<int, int> result = query(0, N - 1, a, b);
        cout << result.first << ' ' << result.second << '\n';
    }
    
    return 0;
}
