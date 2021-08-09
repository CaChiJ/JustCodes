#include <iostream>
#include <vector>

using namespace std;

int DP[21][2000000];
int N;

bool isTrue(int status, int th) {
    return (status & (1 << th)) > 0;
}

int denote(int status, int th, bool value) {
    if(value) {
    	return status | (1 << th);
	} else {
		return status & (~(1 << th));
	}
}

int getMinCost(const int person, int status, int (*costs)[21]) {
    if(person == N) {
        return 0;
    }
    
    if(DP[person][status] != 0) {
        return DP[person][status];
    }
    
    int result = 987654321;
    
    for(int i = 0; i < N; ++i) {
        if(!isTrue(status, i)) {
            int tmp = denote(status, i, true);
            result = min(result, getMinCost(person + 1, tmp, costs) + costs[person][i]);
        }
    }
    
    return DP[person][status] = result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> N;
    
    int costs[N][21];
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> costs[i][j];
        }
    }
    
    cout << getMinCost(0, 0, costs) << endl;
    return 0;
}
