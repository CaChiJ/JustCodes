#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdlib>

typedef long long ll;

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    ll N;
    cin >> N;
    
    vector<ll> solutions(N);
    
    for(auto i = solutions.begin(); i < solutions.end(); ++i) {
        cin >> *i;
    }
    
    sort(solutions.begin(), solutions.end());
	
	ll minSum = LLONG_MAX;
	vector<int> answer(3);
	
	for(auto left = solutions.begin(); left < solutions.end() - 2; ++left) {
		auto mid = left + 1;
		auto right = solutions.end() - 1;
		
		while(mid < right) {
			ll subSum = *left + *mid + *right;
			
			if(subSum == 0) {
				answer[0] = *left;
				answer[1] = *mid;
				answer[2] = *right;
				left = solutions.end();
				break;
			}
			
			if(abs(subSum) < minSum) {
				minSum = abs(subSum);
				answer[0] = *left;
				answer[1] = *mid;
				answer[2] = *right;
			}
			
			if(subSum < 0) {
				mid++;
			} else {
				right--;
			}
		}
	}
    
    cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << '\n';
    
    return 0;
}
