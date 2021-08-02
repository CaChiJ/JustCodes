#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> Pii;
vector< vector<Pii> > edges;
vector<int> dist;
int N, E;

int GetMinDistance(vector< vector<Pii> > &edges, int start, int goal) {
	vector<int> dist(N, -1);
	
    priority_queue< Pii, vector<Pii>, greater<Pii> > pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
    	int taken, vertex;
        tie(taken, vertex) = pq.top();
        pq.pop();
        
        if(dist[vertex] != -1) {
            continue;
        }
        
        dist[vertex] = taken;
        
        for(int i = 0; i < edges[vertex].size(); ++i) {
            if(dist[edges[vertex][i].first] != -1) {
                continue;
            }
            
            pq.push({edges[vertex][i].second + taken, edges[vertex][i].first});
        }
	}
	
	return dist[goal];
}

int main(void) {
    cin >> N >> E;
    
    edges.resize(N);
    dist.resize(N);
    
    for(int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a-1].push_back({b-1, c});
        edges[b-1].push_back({a-1, c});
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    
    pair<int, int> result = {0, 0};
    pair<bool, bool> isExist = {true, true};
    
	// 0 to v1
    
    int subResult = GetMinDistance(edges, 0, v1);
    
	if(subResult == -1) {
    	isExist.first = false;
	} else {
		result.first += subResult;
	}
	
	
	// 0 to v2
	
    subResult = GetMinDistance(edges, 0, v2);
    
	if(subResult == -1) {
		isExist.second = false;
	} else {
		result.second += subResult;
	}
	
	//cout << result.first << ' ' << result.second << '\n';
	
	
	// v1 to v2
	
	subResult = GetMinDistance(edges, v1, v2);
    
	if(subResult == -1) {
    	isExist.first = false;
		isExist.second = false;
	} else {
		result.first += subResult;
		result.second += subResult;
	}
	
	//cout << result.first << ' ' << result.second << '\n';
	
	
	// v1 to N-1
	
	subResult = GetMinDistance(edges, v1, N-1);
    
	if(subResult == -1) {
    	isExist.second = false;
	} else {
		result.second += subResult;
	}
	
	
	// v2 to N-1
	
	subResult = GetMinDistance(edges, v2, N-1);
	
	if(subResult == -1) {
		isExist.first = false;
	} else {
		result.first += subResult;
	}
    
    //cout << result.first << ' ' << result.second << '\n';
    
    if(isExist.first && isExist.second) {
    	cout << min(result.first, result.second) << '\n';
	} else if(isExist.first) {
		cout << result.first << '\n';
	} else if(isExist.second) {
		cout << result.second << '\n';
	} else {
		cout << "-1\n";
	}
    
    return 0;
}
