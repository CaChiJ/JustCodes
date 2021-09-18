#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>

using namespace std;

int requiredCnt[200'000];

int main(void) {
	int TC;
	cin >> TC;
	
	for(int tcCnt = 0; tcCnt < TC; ++tcCnt) {
		int N;
		cin >> N;
		vector<int> adj[N];
		priority_queue< int, vector<int>, greater<int> > pq;
		
		for(int i = 0; i < N; ++i) {
			int K;
			cin >> K;
			requiredCnt[i] = K;
			
			for(int j = 0; j < K; ++j) {
				int required;
				cin >> required;
				required--;
				adj[required].push_back(i);
			}
			
			if(K == 0) {
				pq.push(i);
			}
		}
		
		int understandCnt = 0;
		int result = 0;
		
		while(!pq.empty()) {
			queue<int> q;
			int prior = -1;
			result++;
			
			while(!pq.empty()) {
				int node = pq.top();
				pq.pop();
				
				if(node < prior) {
					q.push(node);
					continue;
				}
				
				if(requiredCnt[node] < 0) {
					continue;
				}
				
				understandCnt++;
				prior = node;
				requiredCnt[node] = -1;
				
				for(int i = 0; i < adj[node].size(); ++i) {
					int to = adj[node][i];
					
					if(requiredCnt[to] <= 0) {
						continue;
					}
					
					requiredCnt[to]--;
					
					if(requiredCnt[to] == 0) {
						pq.push(to);
					}
				}
			}
			
			while(!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
		}
		
		if(understandCnt < N) {
			cout << "-1\n";
		} else {
			cout << result << '\n';
		}
	}
}
