#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    int lopes[100000];

    for (int i = 0; i < N; ++i) {
        cin >> lopes[i];
    }

    sort(lopes, lopes + N);

    int result = -1;

    for (int i = N - 1; i >= 0; --i) {
        int lope = lopes[i];
        int count = N - i;
        
        int maxWeight = lope * count;

        if (maxWeight > result) {
            result = maxWeight;
        }
    }

    cout << result << '\n';

    return 0;
}   