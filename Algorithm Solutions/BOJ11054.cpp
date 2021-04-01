#include <iostream>

using namespace std;

const int MAXN = 1000;
int cache[2][MAXN];
int seq[MAXN];

int LIS(int th)
{
    if(cache[0][th] == 0)
    {
        cache[0][th] = 1;
        for(int i = 0; i < th; ++i)
        {
            if(seq[i] < seq[th])
            {
                cache[0][th] = max(cache[0][th], LIS(i) + 1);
            }
        }
    }
    
    return cache[0][th];
}


int LISREV(int th, const int N)
{
    if(cache[1][th] == 0)
    {
        cache[1][th] = 1;
        for(int i = N - 1; i > th; --i)
        {
            if(seq[i] < seq[th])
            {
                cache[1][th] = max(cache[1][th], LISREV(i, N) + 1);
            }
        }
    }
    
    return cache[1][th];
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    for(int i = 0; i < N; ++i)
    {
        cin>>seq[i];
    }
    
    cache[0][0] = 1;
    cache[1][N-1] = 1;
    
    for(int i = 0; i < N - 1; ++i)
    {
	    LIS(i);
	    LISREV(i, N);
	}
    
    int ret = 0;
    for(int i = 0; i < N; ++i)
    {
        ret = max(ret, cache[0][i] + cache[1][i] - 1);
    }
    
    cout<<ret<<endl;
    
    return 0;
}
