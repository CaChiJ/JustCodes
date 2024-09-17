#include <iostream>
#include <cstring>

using namespace std;

const int offset = 100;

int main(void) {
    int N;
    int count[201];
    memset(count, 0, sizeof(count));
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        
        count[num + offset]++;
    }
    
    int v;
    cin >> v;
    
    cout << count[v + offset];
    return 0;
}