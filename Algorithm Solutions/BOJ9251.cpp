#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 1000;
int cache[MAXN + 1][MAXN + 1];
string str1;
string str2;


int LCS(int th1, int th2)
{
	if(th1 < 0 || th2 < 0)
	{
		return 0;
	}
	
	if(cache[th1][th2] == -1)
	{
		if(str1[th1] == str2[th2])
		{
			cache[th1][th2] = LCS(th1 - 1, th2 - 1) + 1;
		}
		else
		{
			cache[th1][th2] = max(LCS(th1, th2 - 1), LCS(th1 - 1, th2));
		}
		
	}
	
	return cache[th1][th2];
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin>>str1>>str2;
	
	int N = str1.size();
	int M = str2.size();
	
	str1 += '.';
	str2 += '.';
	
	memset(&cache[0][0], -1, sizeof(cache));
	LCS(N, M);
	
	cout<<cache[N][M] - 1<<endl;
	return 0;
}
