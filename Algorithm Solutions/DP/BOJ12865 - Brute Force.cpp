// O(2^n) Brute Force Knapsack solution
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100;
pair<int, int> items[MAXN];

int fillKnapSack(int last, int left)
{
	if(last < 0 || left <= 0)
	{
		return 0;
	}
	
	int ans = fillKnapSack(last - 1, left);
	if(left - items[last].first >= 0)
	{
		ans = max(ans, fillKnapSack(last - 1, left - items[last].first) + items[last].second);
	}
	
	return ans;
}

int main(void)
{	
	int N, K;
	cin>>N>>K;
	
	for(int i = 0; i < N; ++i)
	{
		cin>>items[i].first>>items[i].second;
	}
	
	cout<<fillKnapSack(N - 1, K)<<endl;
	return 0;
}
