#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

typedef pair< int, pair< int, int > > Edge;
typedef pair< int, vector<int> > Planet;
priority_queue< Edge, vector<Edge>, greater<Edge> > edges;

int parent[100003];

int find(int node) {
    if(parent[node] == node) {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void uni(int a, int b) {
    parent[find(b)] = find(a);
}

bool comp1(const Planet &a, const Planet &b) {
    return a.second[0] < b.second[0];
}

bool comp2(const Planet &a, const Planet &b) {
    return a.second[1] < b.second[1];
}

bool comp3(const Planet &a, const Planet &b) {
    return a.second[2] < b.second[2];
}

int main(void) {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        parent[i] = i;
    }
    
    vector<Planet> planets(N);
    
    for(int i = 0; i < N; ++i) {
        planets[i].first = i;
        int x, y, z;
        cin >> x >> y >> z;
        planets[i].second.push_back(x);
        planets[i].second.push_back(y);
        planets[i].second.push_back(z);
    }
    
    sort(planets.begin(), planets.end(), comp1);
    
    for(int i = 0; i < N-1; ++i) {
        edges.push( make_pair(abs(planets[i].second[0] - planets[i+1].second[0]) , make_pair(planets[i].first, planets[i+1].first)) );
    }
     
    sort(planets.begin(), planets.end(), comp2);
    
    for(int i = 0; i < N-1; ++i) {
        edges.push( make_pair(abs(planets[i].second[1] - planets[i+1].second[1]) , make_pair(planets[i].first, planets[i+1].first)) );
    }
    
    sort(planets.begin(), planets.end(), comp3);
    
    for(int i = 0; i < N-1; ++i) {
        edges.push( make_pair(abs(planets[i].second[2] - planets[i+1].second[2]) , make_pair(planets[i].first, planets[i+1].first)) );
    }
    
    int result = 0;
    
    while(!edges.empty()) {
        Edge edge = edges.top();
        edges.pop();
        
        if(find(edge.second.first) != find(edge.second.second)) {
            uni(edge.second.first, edge.second.second);
            result += edge.first;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
