#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

const int MAXN = 500;
int lines[MAXN + 1];
int cache[MAXN + 1];

int LIS(int th)
{
	if(lines[th] == -1)
	{
		return 0;
	}
	
	if(cache[th] == 0)
	{
		cache[th] = 1;
		for(int i = 0; i < th; ++i)
		{
			if(lines[i] < lines[th])
			{
				cache[th] = max(cache[th], LIS(i) + 1);
			}
		}
	}
	
	return cache[th];
}

int main(void)
{
	int K;
	cin>>K;
	
	memset(lines, -1, sizeof(lines));
	
	for(int i =0; i < K; ++i)
	{
		int from, to;
		cin>>from>>to;
		lines[from - 1] = to;
	}
	
	lines[MAXN - 1] = INT_MAX;
	
	int ret = LIS(MAXN - 1) - 1;
	cout<<K - ret<<endl;
	
	return 0;
}
