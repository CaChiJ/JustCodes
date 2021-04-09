#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int DP(int A, int B)
{
	if(A == B)
	{
		return 0;
	}
	
	if(B == 0)
	{
		return INT_MAX - 1;
	}
	
	int ret = INT_MAX;
	
	if(B % 2 == 0)
	{
		ret = min(ret, DP(A, B / 2) + 1);
	}
	
	if(B % 10 == 1)
	{
		ret = min(ret, DP(A, B / 10) + 1);
	}
	
	if(ret == INT_MAX)
	{
		return ret - 1;
	}
	
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int A, B;
	cin>>A>>B;
	
	int ret = DP(A, B);
	
	if(ret == INT_MAX - 1)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ret + 1<<endl;
	}
	
	return 0;
}
