#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> real[200000];
pair<int, int> lFirst[200000];
pair<int, int> rFirst[200000];

int maxEnd[200000];
int minStart[200000];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int TC;
    cin >> TC;
    
    for (int tcCnt=0; tcCnt < TC; ++tcCnt) {
        int N;
        cin >> N;

        for (int i = 0; i < N; ++i) {
            int l, r;
            cin >> l >> r;

            real[i] = {l, r};
            lFirst[i] = {l ,r};
            rFirst[i] = {r, l};
        }

        sort(lFirst, lFirst + N);
        sort(rFirst, rFirst + N);

        int maxE = -1;
        int minS = 2'000'000'000;
        
        for (int i = 0; i < N; ++i) {
            int r = lFirst[i].second;

            if (maxE < r) {
                maxE = r;
            }

            maxEnd[i] = maxE;
        }

        for (int i = N-1; i >= 0; --i) {
            int l = rFirst[i].second;

            if (minS > l) {
                minS = l;
            }

            minStart[i] = minS;
        }

        for (int i = 0; i < N; ++i) {
            int l = real[i].first;
            int r = real[i].second;

            pair<int, int> lp = {l, 2'000'000'000};
            pair<int, int> rp = {r, -1};

            pair<int, int>* ub = upper_bound(lFirst, lFirst + N, lp);
            int meIdx = ub - 1 - lFirst;
            int me = maxEnd[meIdx];

            pair<int, int>* lb = lower_bound(rFirst, rFirst + N, rp);
            int msIdx = lb - rFirst;
            int ms = minStart[msIdx];

            cout << me - ms + 1 - (r - l + 1) << endl;
        }
    }

    return 0;
}