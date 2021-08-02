#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int parent[50003];

vector< pair< int, vector<int> > > players(50003, make_pair(0, vector<int>()));
//bool isVisited[50003];

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
    
    int count = 0;
    
    for(int i = 0; i < N; ++i) {
    	parent[i] = i;
	}
    
    for(int i = 0; i < M; ++i) { 
        int A, B;
        char op;
        cin >> A >> op >> B;
        
        if(op =='<') {
            players[find(A)].second.push_back(find(B));
            players[find(B)].first++;
            count++;
        } else if(op == '>') {
            players[find(B)].second.push_back(find(A));
            players[find(A)].first++;
            count++;
        } else if(op == '=') {
        	players[find(A)].first += players[find(B)].first;
        	uni(A, B);
		}
    }
    
    for(int i = 0; i < N; ++i) {
    	if(find(i) == i) {
    		continue;
		}
		
		for(auto j = players[i].second.begin(); j < players[i].second.end(); ++j) {
			players[find(i)].second.push_back(*j);
		}
	}
    
    queue<int> q;
    
    for(int i = 0; i < N; ++i) {
        if(find(i) == i && players[i].first == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        //isVisited[now] = true;
        
        for(auto i = players[now].second.begin(); i < players[now].second.end(); ++i) {
        	//if(isVisited[find(*i)]) {
        	//	result = false;
        	//	break;
			//}
			
			count--;
			
            players[find(*i)].first--;
            
            if(players[find(*i)].first == 0) {
                q.push(find(*i));
            }
        }
    }
    
    if(count == 0) {
        cout << "consistent\n";
    } else {
        cout << "inconsistent\n";
    }
    
    return 0;
}
