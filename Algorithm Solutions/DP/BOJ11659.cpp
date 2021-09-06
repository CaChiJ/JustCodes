#include <iostream>

using namespace std;

int pSum[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; ++i) {
        cin >> pSum[i];
        pSum[i] += pSum[i-1];
    }
    
    for(int i = 0; i < M; ++i) {
        int start, end;
        cin >> start >> end;
        cout << pSum[end] - pSum[start - 1] << '\n';
    }
    
    return 0;
}
