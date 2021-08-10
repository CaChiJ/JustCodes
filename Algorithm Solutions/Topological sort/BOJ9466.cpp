#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int T;
    cin >> T;
    
    for(int tcCnt = 0; tcCnt < T; ++tcCnt) {
        int N;
        cin >> N;
        
        vector<int> left(N + 1);
        vector< vector<int> > next(N + 1);
            
        for(int i = 1; i <= N; ++i) {
            int who;
            cin >> who;
            
            next[i].push_back(who);
            left[who]++;
        }
        
        queue<int> q;
        
        for(int i = 1; i <= N; ++i) {
            if(left[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int student = q.front();
            q.pop();
            
            for(auto i = next[student].begin(); i < next[student].end(); ++i) {
                left[*i]--;
                if(left[*i] == 0) {
                    q.push(*i);
                }
            }
        }
        
        int result = 0;
        
        for(int i = 1; i <= N; ++i) {
            if(left[i] == 0) {
                result++;
            }
        }
        
        cout << result << endl;
    }
}
