#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if(a.first == b.first) {
		return a.second < b.second;
	}
	
	return a.first < b.first;
}

bool comp2(const pair<int, int>& a, const pair<int, int>& b) {
	if(a.first == b.first) {
		return a.second > b.second;
	}
	
	return a.first < b.first;
}

int main(void) {
	int TC;
	cin >> TC;
	
	for(int tcCnt = 0; tcCnt < TC; ++tcCnt) {
		int N, M;
		cin >> N >> M;
		
		int seq[N * M];
		pair<int, int> sorted[N * M];
		
		for(int i = 0; i < N * M; ++i) {
			cin >> seq[i];
			sorted[i].first = seq[i];
			sorted[i].second = i;
		}
		
		sort(sorted, sorted + N * M, comp);
		
		int result = 0;
		
		for(int i = 0; i < N; ++i) {
			sort(sorted + i * M, sorted + i * M + M, comp2);
			for(int j = 0; j < M; ++j) {
				for(int k = 0; k < j; ++k) {
					if(sorted[i * M + k].second < sorted[i * M + j].second) {
						result++;
					}
				}
			}
		}
		
		/*
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < M; ++j) {
				cout << sorted[i * M + j].first << ' ' << sorted[i * M + j].second << '\n';
			}
		}
		*/
		
		cout << result << '\n';
	}
	
	return 0;
}
