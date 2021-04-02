// DP Knapsack solution
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100;
const int MAXK = 100000;
int cache[MAXN][MAXK];
pair<int, int> items[MAXN];

int fillKnapSack(int last, int left)
{
	if(last < 0 || left <= 0)
	{
		return 0;
	}
	
	if(cache[last][left] == -1)
	{
		cache[last][left] = fillKnapSack(last - 1, left);
		if(left - items[last].first >= 0)
		{
			cache[last][left] = max(cache[last][left], fillKnapSack(last - 1, left - items[last].first) + items[last].second);
		}
	}
	
	return cache[last][left];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
		
	int N, K;
	cin>>N>>K;
	
	for(int i = 0; i < N; ++i)
	{
		cin>>items[i].first>>items[i].second;
	}
	
	int ret = -1;
	for(int i = 0; i < N; ++i)
	{
		ret = max(ret, fillKnapSack(i, K));
	}
	
	cout<<ret<<endl;
	return 0;
}
