#include <iostream>
#include <vector>

using namespace std;

int DP[2002][2002];

bool isPalindrome(vector<int>& seq, int start, int end) {
    if(DP[start][end] != -1) {
        return DP[start][end] == 1 ? true : false;
    }
    
    if(start >= end) {
        return DP[start][end] = true;
    }
    
    if(seq[start] == seq[end]) {
        return DP[start][end] = isPalindrome(seq, start+1, end-1);
    } else {
        return DP[start][end] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            DP[i][j] = -1;
        }
    }
    
    vector<int> seq(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
    }
    
    cin >> M;
    
    for(int i = 0; i < M; ++i) {
        int S, E;
        cin >> S >> E;
        
        if(isPalindrome(seq, S-1, E-1)) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    
    return 0;
}
