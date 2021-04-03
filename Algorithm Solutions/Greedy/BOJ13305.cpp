#include <iostream>
#include <climits>

using namespace std;

const int MAXN = 100000;
int dist[MAXN];
int prices[MAXN];

int main(void)
{
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    dist[0] = 0;
    
    for(int i = 1; i < N; ++i)
    {
        cin>>dist[i];
    }
    
    for(int i = 0; i < N; ++i)
    {
        cin>>prices[i];
    }
    
    int minPrice = INT_MAX;
    unsigned long long distSum = 0;
    unsigned long long result = 0;
    
    for(int i = 0; i < N; ++i)
    {
    	distSum += dist[i];
        if(prices[i] < minPrice)
        {
            result += distSum * minPrice;
            minPrice = prices[i];
            distSum = 0;
        }
    }
    
    result += distSum * minPrice;
    cout<<result<<endl;
    
    return 0;
}
