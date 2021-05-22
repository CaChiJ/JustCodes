#include <iostream>
#include <queue>
#include <vector>
#include <utility>

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
        
        if(x == 0) { 
            if(maxHeap.size() == 0 && minHeap.size() == 0) {
                cout << 0 << '\n';
            } else if(maxHeap.size() == 0) {
                cout << minHeap.top() << '\n';
                minHeap.pop();
            } else if(minHeap.size() == 0) {
                cout << maxHeap.top() << '\n';
                maxHeap.pop();
            } else {
                if(minHeap.top() >= -maxHeap.top()) {
                    cout << maxHeap.top() << '\n';
                    maxHeap.pop();
                } else {
                    cout << minHeap.top() << '\n';
                    minHeap.pop();
                }
            }
        } else {
            if(x > 0) {
                minHeap.push(x);
            } else {
                maxHeap.push(x);
            }
        }
    }
    
    return 0;
}
