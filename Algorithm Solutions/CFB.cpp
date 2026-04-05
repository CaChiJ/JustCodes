#include <iostream>

using namespace std;

int colorCnt[1001];

int main(void) {
    int TC;
    cin >> TC;

    for (int tcCnt = 0; tcCnt < TC; ++tcCnt) {
        int N;
        cin >> N;

        int uniqueCnt = 0;
        int commonCnt = 0;

        for (int i = 0; i <= N; ++i) {
            colorCnt[i] = 0;
        }

        for (int i = 0; i < N; ++i) {
            int c;
            cin >> c;
            colorCnt[c]++;
        }

        for (int i = 0; i <= N; ++i) {
            if (colorCnt[i] == 1) {
                uniqueCnt++;
            } else if (colorCnt[i] > 1) {
                commonCnt++;
            }
        }

        cout << ((uniqueCnt + 1) / 2) * 2 + commonCnt << endl;
    }
}