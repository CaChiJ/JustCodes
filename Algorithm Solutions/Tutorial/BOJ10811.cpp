#include <iostream>

using namespace std;

int baskets[101];

int main(void) {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        baskets[i] = i;
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < (b - a + 1) / 2; ++j) {
            int tmp = baskets[a+j];
            baskets[a+j] = baskets[b-j];
            baskets[b-j] = tmp;
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << baskets[i] << ' ';
    }

    return 0;
}