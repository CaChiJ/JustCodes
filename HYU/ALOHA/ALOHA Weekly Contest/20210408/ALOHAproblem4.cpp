#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int getNan(long long x)
{
	int nan = 0;
	while(x != 0)
	{
		nan += x % 10;
		x /= 10;
	}
	
	return nan;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	int TC;
	cin>>TC;
	
	for(int tcCnt = 0; tcCnt < TC; ++tcCnt)
	{
		long long x;
		cin>>x;
		int s;
		cin>>s;
		
		long long firstNan = x;
		
		long long afterX = x;
		
		long long cnt = 1;
		
		while(getNan(afterX) > s)
		{
			afterX = x - x % (10 * cnt) + (10 * cnt);
			cnt *= 10;
		}
		
		long long finalNan = afterX;
		
		cout<<abs(finalNan - firstNan)<<endl;
	}
	
	return 0;
}
