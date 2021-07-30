#include <iostream>
#include <algorithm>

using namespace std;

vector<long long> pSum1;
vector<long long> pSum2;

vector<int> items1;
vector<int> items2;

void doSum(vector<int>& v, vector<long long>& result, int now, long long pSum) {
    if(now >= v.size()) {
        result.push_back(pSum);
        return;
    }
    
    doSum(v, result, now+1, pSum);
    doSum(v, result, now+1, pSum + v[now]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, C;
    cin >> N >> C;
    
    for(int i = 0; i < N / 2; ++i) {
        int tmp;
        cin >> tmp;
        items1.push_back(tmp);
    }
    
    for(int i = N / 2; i < N; ++i) {
        int tmp;
        cin >> tmp;
        items2.push_back(tmp);
    }
    
    doSum(items1, pSum1, 0, 0);
    doSum(items2, pSum2, 0, 0);
    
    sort(pSum1.begin(), pSum1.end());
    sort(pSum2.begin(), pSum2.end());
    
    long long result = 0;
    
    for(auto i = pSum1.begin(); i < pSum1.end(); ++i) {
        result += upper_bound(pSum2.begin(), pSum2.end(), C-*i) - pSum2.begin();
    }
    
    cout << result << '\n';
    
    return 0;
}
