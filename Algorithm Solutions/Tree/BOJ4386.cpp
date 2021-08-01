#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

typedef struct
{
    double dist;
    pair<int, int> nodes;
} Edge;

typedef struct
{
	bool operator()(Edge &a, Edge &b) {
		return a.dist > b.dist;
	}
} Compare;

priority_queue< Edge, vector<Edge>, Compare > pq;

int parent[103];

int find(int node) {
    if(parent[node] == node) {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void uni(int a, int b) {
    parent[find(b)] = find(a);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int n;
    cin >> n;
    
    vector< pair<double, double> > nodes(n);
    
    for(int i = 0; i < n; ++i) {
    	parent[i] = i;
	}
    
    for(int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        
        for(int j = 0; j < i; ++j) {
            Edge edge;
            edge.dist = sqrt(pow(nodes[j].first - x, 2) + pow(nodes[j].second - y, 2));
            edge.nodes = make_pair(i, j);
            
            pq.push(edge);
        }

        nodes[i] = make_pair(x, y);
    }
    
    double result = 0.0;
    
    while(!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        
        if(find(edge.nodes.first) != find(edge.nodes.second)) {
            uni(edge.nodes.first, edge.nodes.second);
            result += edge.dist;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
