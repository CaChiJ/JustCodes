#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin>>N>>K;
    
    int coins[N];
    
    for(int i = 0; i < N; ++i)
    {
        cin>>coins[i];
    }
    
    int result = 0;
    
    for(int i = N - 1; i >= 0 ; --i)
    {
        result += K / coins[i];
        K %= coins[i];
    }
    
    cout<<result<<endl;
    
    return 0;
}
