#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
    
vector< pair<int, int> > station(10033);
priority_queue<int> pq;

bool comp(int n, pair<int, int> const &p) {
	return p.first > n;
}

bool comp2(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        cin >> station[i].first >> station[i].second;
    }
    
    sort(station.begin(), station.begin() + N);
    
    int L, fuel;
    cin >> L >> fuel;
    
    int result = 0;
    
    auto priorB = station.begin();
    
    while(fuel < L) {
        auto ub = upper_bound(station.begin(), station.begin() + N, fuel, comp);
        
        for(auto i = priorB; i < ub; ++i) {
            pq.push((*i).second);
        }
        
        priorB = ub;
        
        if(pq.empty()) {
            break;
        }
        
        int maxFuel = pq.top();
        pq.pop();
        
        fuel += maxFuel;
        result++;
    } 
    
    if(fuel >= L) {
        cout << result << '\n';
    } else {
        cout << "-1\n";
    }
    
    return 0;
}
