#include <iostream>

using namespace std;

const int MAX_N = 50;
const int MAX_M = 50;
bool lamps[MAX_N][MAX_M];
bool buttons[MAX_M];

int solution(int N, int M, int K, int column) {
    if(column >= M || K <= 0) {
        int count = 0;
        
        for(int i = 0; i < N; ++i) {
            bool rowOn = true;
            
            for(int j = 0; j < M; ++j) {
                if(!(lamps[i][j] != buttons[j])) {
                    rowOn = false;
                    break;
                }
            }
            
            if(rowOn) {
                count++;
            }
        }
        
        return count;
    }
    
    buttons[column] = false;
    int result1 = solution(N, M, K, column+1);
    buttons[column] = true;
    int result2 = solution(N, M, K-1, column+1);
    
    return max(result1, result2);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, K;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int status;
            scanf("%1d", &status);
            
            lamps[i][j] = status == 1;
        }
    }
    
    cin >> K;
    
    cout << solution(N, M, K, 0) << endl;
    
    return 0;
}
