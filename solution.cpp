#include <iostream>
#include <string.h>

using namespace std;

int table[2'000'000][8];
int amount[2'000'000][3];

int N;

void check(int* flag, int pos, int val) {
    if (val == 0) {
        *flag = (*flag) & ~(1 << pos);
    } else {
        *flag = (*flag) | (1 << pos);
    }
}

int valueOf(int flag, int pos) {
    return 1 & (flag >> pos);
}


int solution(int column, int possible) {
    if (column >= N) {
        return 0;
    }

    if (table[column][possible] == -1) {
        // case 1 : 시추하지 않음
        int result = solution(column + 1, 7);

        int p1 = valueOf(possible, 0);
        int p2 = valueOf(possible, 1);
        int p3 = valueOf(possible, 2);

        // case 2 : 첫 번째 행만 시추
        if (p1) {
            result = max(result, amount[column][0] + solution(column + 1, 6));
        }

        // case 3 : 두 번째 행만 시추
        if (p2) {
            result = max(result, amount[column][1] + solution(column + 1, 5));
        }

        // case 4 : 세 번째 행만 시추
        if (p3) {
            result = max(result, amount[column][2] + solution(column + 1, 3));
        }

        // case 5 : 첫 번째, 세 번째 행 시추
        if (p1 && p3) {
            result = max(result, amount[column][0] + amount[column][2] + solution(column + 1, 2));
        }

        table[column][possible] = result;
    }

    return table[column][possible];
}

int main(void) {
    scanf("%d", &N);

    // init table to -1
    memset(table, -1, sizeof(table));

    // input
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < N; ++c) {
            scanf("%d", &(amount[c][r]));
        }
    }

    // output
    printf("%d\n", solution(0, 7));

    return 0;
}