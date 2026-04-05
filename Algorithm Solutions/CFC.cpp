#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

char str[200001];
pair<int, int> diff[200001];

int main(void) {
    int TC;
    cin >> TC;

    for (int tcCnt=0; tcCnt < TC; ++tcCnt) {
        int N, K;
        cin >> N >> K;

        cin >> str;

        int aCnt = 0;
        int bCnt = 0;

        for (int i = N-1; i >= 0; --i) {
            char fish = str[i];

            if (fish == '1') {
                bCnt++;
            } else {
                aCnt++;
            }

            diff[i] = {aCnt - bCnt, i};
        }

        sort(diff+1, diff+N);
        
        int scoreDiff = 0;
        int cut = -2;

        for (int i = 1; i < N; ++i) {
            int negDiff = -diff[i].first;
            // int groupHead = diff[i].second;

            if (negDiff <= 0) {
                break;
            }

            scoreDiff += negDiff;

            if (scoreDiff >= K) {
                cut = i;
                break;
            }
        }

        cout << cut + 1 << endl;
    }
}