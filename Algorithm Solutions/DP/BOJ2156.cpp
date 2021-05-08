#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 10000;
int cache[MAXN];
int n;
int inputs[MAXN];

int getMax(int now)
{
	if(now >= n)
	{
		return 0;
	}
	
    if(cache[now] == -1)
    {
        cache[now] = max(getMax(now+1), inputs[now] + getMax(now+2));
        
		if(now < n-1)
        {
        	cache[now] = max(cache[now], inputs[now] + inputs[now+1] + getMax(now+3));	
		}
    }
    
    return cache[now];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(cache, -1, MAXN*4);
    
    cin>>n;
    
    for(int i = 0 ; i < n; ++i)
    {
        cin>>inputs[i];
    }
    
    cout<<getMax(0)<<endl;
    
    return 0;
}
