#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
int cache[MAXN];
int seq[MAXN];

int maxSum(int th)
{
	
    if(cache[th] == INT_MAX)
    {
        cache[th] = max(maxSum(th - 1) + seq[th], seq[th]);
    }
    
    return cache[th];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    for(int i = 0; i < N; ++i)
    {
        cin>>seq[i];
        cache[i] = INT_MAX;
    }
    cache[0] = seq[0];
    
    for(int i = 0; i < N; ++i)
    {
        maxSum(i);
    }
    
    cout<<*max_element(cache, cache + N)<<endl;
    return 0;
}
