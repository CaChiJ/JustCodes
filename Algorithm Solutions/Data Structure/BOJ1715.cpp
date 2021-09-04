#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int result = 0;
    int N;
    cin >> N;
    
    priority_queue< int, vector<int>, greater<int> > pq;
    
    for(int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        result += a + b;
        pq.push(a + b);
    }
    
    cout << result << endl;
    
    return 0;
}
