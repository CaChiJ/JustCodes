#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool isValid[1'000'001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int TC;
    cin >> TC;
    
    for(int tcCnt = 0; tcCnt < TC; ++tcCnt) {
    	memset(isValid, false, sizeof(isValid));
        int opCnt;
        cin >> opCnt;
        priority_queue<pair<int, int> > maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;
        
        for(int op = 0; op < opCnt; ++op) {
            char oper;
            cin >> oper;
            switch(oper) {
                case 'I':
                    int number;
                    cin >> number;
                    maxHeap.push({number, op});
                    minHeap.push({number, op});
                    isValid[op] = true;
                    
                    break;
                case 'D':
                    int dir;
                    cin >> dir;
                    
                    pair<int, int> removed;
                    
                    while(!minHeap.empty() && !isValid[minHeap.top().second]) {
                    	minHeap.pop();
					}
					
					while(!maxHeap.empty() && !isValid[maxHeap.top().second]) {
						maxHeap.pop();
					}
                    
                    if(dir == -1) {
                    	if(minHeap.size() == 0) {
                    		break;
						}
                        removed = minHeap.top();
                        minHeap.pop();
                    } else if(dir == 1) {
						if(maxHeap.size() == 0) {
                        	break;
                    	}
                        removed = maxHeap.top();
                        maxHeap.pop();
                    } else {
                        cout << "ERROR!\n";
                    }
                    
                    isValid[removed.second] = false;
                    
                    while(!minHeap.empty() && !isValid[minHeap.top().second]) {
                    	minHeap.pop();
					}
					
					while(!maxHeap.empty() && !isValid[maxHeap.top().second]) {
						maxHeap.pop();
					}
                    
                    break;
            }
        }
		
		while(!minHeap.empty() && !isValid[minHeap.top().second]) {
            minHeap.pop();
		}
			
		while(!maxHeap.empty() && !isValid[maxHeap.top().second]) {
			maxHeap.pop();
		}
            
        if(maxHeap.empty() && minHeap.empty()) {
            cout << "EMPTY" << endl;
        } else {
            cout << maxHeap.top().first << ' ' << minHeap.top().first << endl;
        }
    }
    
    
    return 0;
}
