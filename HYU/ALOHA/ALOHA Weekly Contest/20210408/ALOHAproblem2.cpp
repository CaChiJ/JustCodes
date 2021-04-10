#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 10000;
bool isSafe[MAXN + 1];
bool infected[MAXN + 1];

int main(void)
{
	ios_base::sync_with_stdio(false);
	int N, M, K;
	cin>>N>>M>>K;
	
	int F;
	cin>>F;
	infected[F] = true;
	
	for(int i = 0; i < M; ++i)
	{
		int tmp;
		cin>>tmp;
		isSafe[tmp] = true;
	}
	
	for(int i = 0; i < K; ++i)
	{
		int personCnt;
		cin>>personCnt;
		
		int persons[personCnt];
		bool infection = false;
		
		for(int i = 0; i < personCnt; ++i)
		{
			cin>>persons[i];
			
			if(infected[persons[i]])
			{
				infection = true;
			}
		}
		
		if(infection)
		{
			for(int i = 0; i < personCnt; ++i)
			{
				infected[persons[i]] = !isSafe[persons[i]] || infected[persons[i]];
			}
		}
	}
	
	int result = 0;
	for(int i = 1; i <= N; ++i)
	{
		if(infected[i])
		{
			++result;
		}
	}
	
	cout<<result<<endl;
	
	return 0;
}
