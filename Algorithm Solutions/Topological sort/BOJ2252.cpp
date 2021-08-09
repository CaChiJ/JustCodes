#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    
    vector<int> left(N, 0);
    vector< vector<int> > next(N);
    
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        
        left[b]++;
        next[a].push_back(b);
    }
    
    queue<int> q;
    
    for(int i = 0; i < N; ++i) {
        if(left[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int student = q.front();
        q.pop();
        
        cout << student + 1 << ' ';
        
        for(int i = 0; i < next[student].size(); ++i) {
            left[next[student][i]]--;
            if(left[next[student][i]] == 0) {
                q.push(next[student][i]);
            }
        }
    }
    
    return 0;
}
