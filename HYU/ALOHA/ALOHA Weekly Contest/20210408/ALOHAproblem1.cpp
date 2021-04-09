#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	
	vector<int> result;
	
	for(int i = 0; i < N; ++i)
	{
		int a, b;
		cin>>a>>b;
		
		if(a < 10 || b > 10)
		{
			continue;
		}
		
		result.push_back(i);
	}
	
	sort(result.begin(), result.end());
	
	for(auto it = result.begin(); it < result.end(); ++it)
	{
		cout<<*it<<' ';
	}
	
	return 0;
}
