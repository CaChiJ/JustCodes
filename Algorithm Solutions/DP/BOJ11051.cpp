#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1000;
int table[MAXN + 1][MAXN + 1];

int DP(int N, int K)
{
    if(K == N || K == 0)
    {
        return 1;
    }
    
    if(table[N][K] == -1)
    {
        table[N][K] = DP(N - 1, K - 1) + DP(N - 1, K);
    }
    
    return table[N][K] % 10007;
}

int main(void)
{
    int N, K;
    cin>>N>>K;
    
    memset(table, -1, sizeof(table));
    cout<<DP(N, K)<<endl;
    
    return 0;
}
