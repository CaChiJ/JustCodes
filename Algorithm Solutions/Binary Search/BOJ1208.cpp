#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> seq;
vector<int> seq2;
vector<int> sums;
long long result = 0;
int N, S;

void marking(int now, int pSum) {
    if(now >= seq.size()) {
        sums.push_back(pSum);
        return;
    }
    
    marking(now + 1, pSum);
    marking(now + 1, seq[now] + pSum);
}

void finding(int now, int pSum) {
    if(now >= seq2.size()) {
        auto lb = lower_bound(sums.begin(), sums.end(), -pSum + S);
        auto ub = upper_bound(sums.begin(), sums.end(), -pSum + S);
        result += ub - lb;
        return;
    }
    
    finding(now + 1, pSum);
    finding(now + 1, seq2[now] + pSum);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> S;
    
    int mid = N / 2;
    int left = N - mid;
    
    for(int i = 0; i < mid; ++i) {
        int tmp;
        cin >> tmp;
        seq.push_back(tmp);
    }
    
    marking(0, 0);
    sort(sums.begin(), sums.end());
    
    for(int i = 0; i < left; ++i) {
        int tmp;
        cin >> tmp;
        seq2.push_back(tmp);
    }
    
    finding(0, 0);
    
    if(S == 0) {
    	result -= 1;
	}
	
    cout << result << '\n';
    
    return 0;
}
