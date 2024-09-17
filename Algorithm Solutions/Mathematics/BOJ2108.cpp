#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
    const int NONE = -99999;

    int N;
    cin >> N;

    int elem[500'000];

    for (int i = 0; i < N; ++i) {
        cin >> elem[i];
    }
	
	sort(elem, elem + N);

    // 산술 평균
    int sum = 0;

    for (int i = 0; i < N; ++i) {
        sum += elem[i];
    }

    int average = round(sum / (double) N);
    cout << average << '\n';

    // 중앙값
    int median = elem[N / 2];
    cout << median << '\n';

    // 최빈값
    int appearCnt[8001] = { 0 };
    int maxAppearCnt = 0;
    
    for (int i = 0; i < N; ++i) {
        appearCnt[elem[i] + 4000]++;

        if (maxAppearCnt < appearCnt[elem[i] + 4000]) {
            maxAppearCnt = appearCnt[elem[i] + 4000];
        }
    }

    int mode = NONE;

    for (int i = 0; i < 8001; ++i) {
        if (appearCnt[i] != maxAppearCnt) {
            continue;
        }

        if (mode == NONE) {
            mode = i - 4000;
        } else {
            mode = i - 4000;
            break;
        }
    }

    cout << mode << '\n';

    // 범위
    int maxValue = -10000;
    int minValue = 10000;

    for (int i = 0; i < N; ++i) {
        if (maxValue < elem[i]) {
            maxValue = elem[i];
        }

        if (minValue > elem[i]) {
            minValue = elem[i];
        }
    }

    cout << maxValue - minValue << '\n';

}