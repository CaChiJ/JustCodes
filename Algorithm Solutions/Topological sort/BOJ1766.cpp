#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;


int main(void) {
    int N, M;
    cin >> N >> M;
    
    vector< pair< int, vector<int> > > problems(N+1, make_pair(0, vector<int>()));
    
    for(int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        
        problems[B].first++;
        problems[A].second.push_back(B);
    }
    
    priority_queue< int, vector<int>, greater<int> > pq;
    
    for(int i = 1; i <= N; ++i) {
        if(problems[i].first == 0) {
            pq.push(i);
        }
    }
    
    while(!pq.empty()) {
        int now = pq.top();
        pq.pop();
        
        cout << now << ' ';
        
        for(auto i = problems[now].second.begin(); i < problems[now].second.end(); ++i) {
            problems[*i].first--;
            
            if(problems[*i].first == 0) {
                pq.push(*i);
            }
        }
    }
    
    return 0;
}
