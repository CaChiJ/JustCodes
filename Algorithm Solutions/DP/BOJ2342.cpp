#include <iostream>
#include <vector>

using namespace std;

int DP[100000][5][5];
vector<int> inputs;

int getCost(int from, int to) {
    if(from == to) {
        return 1;
    } else if(from == 0 || to == 0) {
        return 2;
    } else if(from % 2 != to % 2) {
        return 3;
    } else {
    	return 4;
	}
}

int DFS(int left, int right, int count) {
    // base case
    if(count == inputs.size()) {
        return 0;
    }
    
    if(DP[count][left][right] != 0) {
        return DP[count][left][right];
    }
    
    if(left == inputs[count] || right == inputs[count]) {
        DP[count][left][right] = DFS(left, right, count + 1) + 1;
    } else {
        DP[count][left][right] = min(DFS(inputs[count], right, count + 1) + getCost(left, inputs[count]),
                   DFS(left, inputs[count], count + 1) + getCost(right, inputs[count]));
    }
    
    //cout << left << ' ' << right << ' ' << count << ' ' << DP[count][left][right] << endl;
    return DP[count][left][right];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    do {
        int input;
        cin >> input;
        inputs.push_back(input);
    } while(inputs.back() != 0);
    
    inputs.pop_back();
    
    cout << DFS(0, 0, 0) << endl;
    
    return 0;
}
