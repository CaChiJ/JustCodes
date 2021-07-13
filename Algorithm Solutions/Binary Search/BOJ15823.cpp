#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;
    
    vector<int> card(N);
    cin >> card[0];
    
    for(int i = 1; i < N; ++i) {
        cin >> card[i];
    }
    
    int left = 1;
    int right = N / M;
    
    while(left < right) {
        int mid = (left + right) / 2.0 + 0.5;
        bool visited[500'001];
        memset(visited, false, sizeof(visited));
        
        int start = 0;
        int end = 0;
        int packCnt = 0;
	
        for(int i = 0; i < N; ++i) {
            if(visited[card[i]]) {
                while(card[start] != card[i]) {
                    visited[card[start]] = false;
                    start++;
                }
                start++;
            }
             
            end++;
            visited[card[i]] = true;
	    
            if(end - start >= mid) {
            	for(int j = start; j < end; ++j) {
            		visited[card[j]] = false;
		}
		
                start = end;
                packCnt++;
            }
        }
        
        if(packCnt < M) {
            right = mid-1;
        } else {
            left = mid;
        }
    }
    
    cout << left << endl;
    
    return 0;
}
