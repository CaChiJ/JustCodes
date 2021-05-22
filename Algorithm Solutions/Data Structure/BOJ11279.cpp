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
    
    priority_queue<int> pq;
    for(int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        if(tmp == 0) {
            if(pq.size() == 0) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(tmp);
        }
    }
    
    return 0;
}
