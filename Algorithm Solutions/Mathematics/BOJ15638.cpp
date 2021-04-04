#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 100000;
bool isPrime[MAXN];

int main(void)
{
    ios_base::sync_with_stdio(false);
    
    memset(isPrime, -1, sizeof(isPrime));
    
    int N;
    cin>>N;
    
    for(int i = 0; i < N; ++i)
    {
        int tmp;
        cin>>tmp;
    }
    
    for(int i = 2; i <= sqrt(N); ++i)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    
    if(isPrime[N])
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    return 0;
}
