#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    int seq[100000];
    int lisFrom[100000];

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    // i번째 수부터 마지막까지의 가장 긴 증가하는 부분수열 구하기
    vector<int> table;

    for (int i = N - 1; i >= 0; --i) {
        int val = seq[i];
        
        if (table.empty() || table[table.size() - 1] > val) {
            table.push_back(val);
            lisFrom[i] = table.size();
            continue;
        }

        int left = 0;
        int right = table.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (table[mid] > val) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        table[right] = seq[i];
        lisFrom[i] = right + 1;
    }

    // for (int i = 0; i < N; ++i) {
    //     cout << lisFrom[i] << ' ';
    // }

    table.clear();
    int maxLen = 0;
    
    for (int i = 0; i < N; ++i) {
        int val = seq[i];

        if (table.empty() || table[table.size() - 1] < val) {
            table.push_back(val);
            continue;
        } else if (table[table.size() - 1] == val) {
            continue;
        }

        maxLen = max(maxLen, (int) table.size() + lisFrom[i]);
        
        int idx = lower_bound(table.begin(), table.end(), val) - table.begin();
        table[idx] = val;
    }

    cout << maxLen << '\n';

    return 0;
}