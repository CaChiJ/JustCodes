#include <iostream>

using namespace std;

int parent[55];
int attCount[55];
bool doKnow[55];
bool isVisited[55];

int find(int node) {
    if(parent[node] == node) {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void uni(int a, int b) {
    if(find(a) == find(b)) {
        return;
    }
    
    attCount[find(a)] += attCount[find(b)];
    parent[find(b)] = find(a);
}


int main(void) {
    int N, M;
    cin >> N >> M;
    
    int K;
    cin >> K;
    
    for(int i = 0; i < N; ++i) {
        parent[i] = i;
    }
    
    for(int i = 0; i < K; ++i) {
        int tmp;
        cin >> tmp;
        doKnow[tmp-1] = true;
    }
    
    for(int i = 0; i < M; ++i) {
        int attendance;
        cin >> attendance;
        
        int firstMan;
        
        for(int j = 0; j < attendance; ++j) {
            if(j == 0) {
                cin >> firstMan;
                attCount[find(firstMan-1)] += 1;
                continue;
            }
            
            int man;
            cin >> man;
            uni(firstMan-1, man-1);
        }
    }
    
    int result = 0;
    
    for(int i = 0; i < N; ++i) {
        if(isVisited[find(i)]) {
            continue;
        }
        
        isVisited[find(i)] = true;
        bool doTheyKnow = false;
        
        for(int j = i; j < N; ++j) {
            if(find(i) == find(j)) {
                if(doKnow[j]) {
                    doTheyKnow = true;
                    break;
                }
            }
        }
        
        if(!doTheyKnow) {
            result += attCount[find(i)];
        }
        
    }
    
    cout << result << endl;
    
    return 0;
}
