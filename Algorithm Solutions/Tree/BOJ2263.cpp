#include <iostream>
#include <vector>

using namespace std;

void GetPreorder(vector<int> &in, vector<int> &post, vector<int> &pre, int start, int end, int a, int b) {
	if(start == end) {
		return;
	}
	
    int root = post[b-1];
    
    pre.push_back(root);
    
    int mid = -1;
    
    for(int i = start; i < end; ++i) {
        if(in[i] == root) {
            mid = i;
            break;
        }
    }
    
    GetPreorder(in, post, pre, start, mid, a, a + mid - start);
    GetPreorder(in, post, pre, mid+1, end, a + mid - start, b - 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N;
    cin >> N;
    
    vector<int> in(N);
    vector<int> post(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> in[i];
    }
    
    for(int i = 0; i < N; ++i) {
        cin >> post[i];
    }
    
    vector<int> pre;
    GetPreorder(in, post, pre, 0, N, 0, N);
    
    for(auto i = pre.begin(); i < pre.end(); ++i) {
        cout << *i << ' ';
    }
    
    return 0;
}
