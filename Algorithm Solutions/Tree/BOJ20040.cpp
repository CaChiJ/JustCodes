#include <iostream>

using namespace std;

int parent[500003];

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
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i) {
        parent[i] = i;
    }
    
    int result = 0;
    
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        
        if(find(a) == find(b)) {
        	if(result == 0) {
            	result = i + 1;
			}
        }
        
        uni(a, b);
    }
    
    cout << result << endl;
    return 0;
}
