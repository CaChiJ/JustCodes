#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

const int START = 0;
const int DEST = 1;
const int MAX_N = 1000;

vector< pair<int, int> > graph[MAX_N]; 
int dist[MAX_N];
int counts[MAX_N];

int main(void) {
	int N, M;
	cin >> N >> M;
	
	memset(dist, -1, sizeof(dist));
	
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	
	// 최단거리 구하기
	
	priority_queue< pair<int, int> > pq;	// {distance, node}
	pq.push({0, DEST});
	
	while(!pq.empty()) {
		int d = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if (dist[now] != -1) {
			continue;
		}
		
		dist[now] = d;
		
		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i].first;
			int w = graph[now][i].second;
			
			if (dist[next] != -1) {
				continue;
			}
			
			pq.push({-(d + w), next});
		}
	}
	
	/*
	for (int i = 0; i < N; ++i) {
		cout << dist[i] << "\n";
	}
	*/
	
	// 경우의 수 세기
	vector< pair<int, int> > indexes;

	for (int i = 0; i < N; ++i) {
		indexes.push_back({dist[i], i});
	}
	
	sort(indexes.begin(), indexes.end());
	counts[1] = 1;
	
/*
	for (int i = 0; i < N; ++i) {
		cout << indexes[i].first << ' ' << indexes[i].second << '\n';
	}
	*/
	
	for (int i = 0; i < N; ++i) {
		int node = indexes[i].second;
		
		for (int j = 0; j < graph[node].size(); ++j) {
			int to = graph[node][j].first;
			
			if (dist[node] >= dist[to]) {
				continue;
			}
			
			counts[to] += counts[node];
		}
	}
	
	/*
	for (int i = 0; i < N; ++i) {
		cout << counts[i] << '\n';
	}
	*/
	
	cout << counts[0] << endl;
	
	return 0;
}

/*
4 5
1 3 5
1 4 10
3 4 3
4 2 1
3 2 1
*/