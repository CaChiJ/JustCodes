#include <iostream>
#include <vector>

using namespace std;

vector<long long> prefixSum;

long long init(vector<long long>& values, int left, int right, int node) {
    if(left == right) {
        return prefixSum[node] = values[left];
    }
    
    int mid = (left + right) / 2;
    return prefixSum[node] = init(values, left, mid, node * 2) + init(values, mid + 1, right, node * 2 + 1);
}

long long getSum(int left, int right, int node, int nodeLeft, int nodeRight) {
    if(nodeLeft == left && nodeRight == right) {
        return prefixSum[node];
    }
    
    int mid = (nodeLeft + nodeRight) / 2;
    long long result = 0;
    
    if(right < mid + 1) {
        result = getSum(left, right, node * 2, nodeLeft, mid);
    } else if(left > mid) {
        result = getSum(left, right, node * 2 + 1, mid+1, nodeRight);
    } else {
        result += getSum(left, mid, node * 2, nodeLeft, mid);
        result += getSum(mid + 1, right, node * 2 + 1, mid + 1, nodeRight);
    }
    
    return result;
}

long long changeValue(int idx, long long value, int node, int left, int right) {
    if(idx == left && idx == right) {
        long long diff = value - prefixSum[node];
        prefixSum[node] = value;
        return diff;
    }
    
    int mid = (left + right) / 2;
    long long diff = 0;
    if(idx <= mid) {
        diff = changeValue(idx, value, node * 2, left, mid);
        prefixSum[node] += diff;
    } else {
        diff = changeValue(idx, value, node * 2 + 1, mid + 1, right);
        prefixSum[node] += diff;
    }
    
    return diff;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<long long> inputs(N+1);
    
    for(int i = 1; i <= N; ++i) {
        cin >> inputs[i];
    }
    
    prefixSum.resize(4 * N + 1);
    
    init(inputs, 1, N, 1);
    
    for(int i = 0; i < M + K; ++i) {
    
        long long a, b, c;
        cin >> a >> b >> c;
        
        switch(a) {
            case 1:
                changeValue(b, c, 1, 1, N);
                break;
            case 2:
                cout << getSum(b, c, 1, 1, N) << '\n';
                break;
        }
    }
    
    return 0;
}
