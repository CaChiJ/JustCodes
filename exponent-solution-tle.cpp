#include <iostream>

using namespace std;

int amount[2'000'000][3];
int N;

int solution(int column, int p1, int p2, int p3) {
    if (column >= N) {
        return 0;
    }

    int result = solution(column + 1, 1, 1, 1);

    if (p1) {
        result = max(result, amount[column][0] + solution(column + 1, 0, 1, 1));
    }

    if (p2) {
        result = max(result, amount[column][1] + solution(column + 1, 1, 0, 1));
    }
    
    if (p3) {
        result = max(result, amount[column][2] + solution(column + 1, 1, 1, 0));
    }
    
    if (p1 && p3) {
        result = max(result, amount[column][0] + amount[column][2] + solution(column + 1, 0, 1, 0));
    }

    return result;
}

int main(void) {
    scanf("%d", &N);
    
    // input
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < N; ++c) {
            scanf("%d", &amount[c][r]);
        }
    }

    // output
    printf("%d\n", solution(0, 1, 1, 1));

    return 0;
}