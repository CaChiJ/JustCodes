#include <iostream>
#include <map>
#include <string>

using namespace std;

int parent[200003];
int count[200003];

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
	
    count[find(a)] += count[find(b)];
    parent[find(b)] = find(a);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int T;
    cin >> T;
    
    for(int tcCnt = 0; tcCnt < T; ++tcCnt) {
        for(int i = 0; i < 200003; ++i) {
            parent[i] = i;
            count[i] = 1;
        }
        
        map<string, int> people;
        
        int F;
        cin >> F;
        
        for(int i = 0; i < F; ++i) {
            string a, b;
            cin >> a >> b;
            
            if(people.count(a) == 0) {
                people[a] = people.size();
            }
            
            if(people.count(b) == 0) {
                people[b] = people.size();
            }
            
            uni(people[a], people[b]);
            
            cout << count[find(people[a])] << '\n';
        }
    }
    
    return 0;
}
