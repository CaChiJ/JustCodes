#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool isPrime[4000005];

queue<int> q;

int main(void)
{
    int N;
    cin >> N;
    
    memset(isPrime, true, sizeof(isPrime));
    
    long long partialSum = 0;
    int result = 0;
    
    for(int i = 2; i <= N; ++i) {
        if(!isPrime[i]) {
            continue;
        }
        
        for(int j = 2*i; j <= N; j += i) {
            isPrime[j] = false;
        }
        
        partialSum += i;
        q.push(i);
        
        
        if(partialSum > N) {
            while(partialSum > N) {
                partialSum -= q.front();
                q.pop();
            }
        }
        
        if(partialSum == N) {
            result++;
            partialSum -= q.front();
            q.pop();
        }
    }
    
    cout << result << endl;
    
    return 0;
}
