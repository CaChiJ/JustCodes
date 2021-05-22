#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for(int i = 0; i < N; ++i) {
    	int x;
        cin >> x;
        
        if(maxHeap.size() == 0) {
        	maxHeap.push(x);
        	cout << x << '\n';
        	continue;
		}
        
        if(x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }
        
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        cout << maxHeap.top() << '\n';
    }
    
    return 0;
}
