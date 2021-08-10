#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, M;
    cin >> N >> M;
    
    vector<int> left(N + 1);
    vector< vector<int> > next(N + 1);
    
    for(int i = 0; i < M; ++i) {
        int singerCount;
        cin >> singerCount;
        
        int prior;
        cin >> prior;
        
        for(int j = 1; j < singerCount; ++j) {
            int singer;
            cin >> singer;
            
            left[singer]++;
            next[prior].push_back(singer);
            
            prior = singer;
        }
    }
    
    queue<int> q;
    queue<int> result;
    
    for(int i = 1; i <= N; ++i) {
        if(left[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int singer = q.front();
        result.push(singer);
        q.pop();
        
        for(auto i = next[singer].begin(); i < next[singer].end(); ++i) {
            left[*i]--;
            if(left[*i] == 0) {
                q.push(*i);
            }
        }
    }
    
    if(result.size() == N) {
        while(!result.empty()) {
            cout << result.front() << '\n';
            result.pop();
        }
    } else {
        cout << "0\n";
    }
    
    return 0;
}
