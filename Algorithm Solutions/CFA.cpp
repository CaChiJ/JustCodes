#include <iostream>
#include <algorithm>

using namespace std;

int chests[50];

int main(void) {
    int TC;
    cin >> TC;

    for (int tcCnt = 0; tcCnt < TC; ++tcCnt) {
        int N, K;
        cin >> N >> K;

        int sum = 0;
        int minNum = 987654321;

        for (int i = 0; i < N; ++i) {
            int a;
            cin >> a;
            chests[i] = a;
        }

        sort(chests, chests + N);

        for (int i = N - 1; i >= 0; --i) {
            sum += chests[i];

            if (sum > K) {
                continue;
            }

            if (minNum > K - sum) {
                minNum = K - sum;
            }
        }

        cout << minNum << endl;
    }

    return 0;
}