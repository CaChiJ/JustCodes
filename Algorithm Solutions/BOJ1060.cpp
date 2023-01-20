#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_L = 50;

int main(void) {
    int L;
    scanf("%d", &L);

    int S[MAX_L];

    for (int i = 0; i < L; ++i) {
        scanf("%d", S + i);
    }

    sort(S, S + L);

    int N;
    scanf("%d", &N);

    for (int l = 0; l < L; ++l) {
        
    }

    return 0;
}