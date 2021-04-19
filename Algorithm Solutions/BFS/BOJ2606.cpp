#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 25;
int map[MAXN][MAXN];
int N;

int delta[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(int row, int col)
{
	if(map[row][col] == 0
		|| row < 0 || row >= N
		|| col < 0 || col >= N)
	{
		return 0;
	}
	
	map[row][col] = 0;
	int ret = 1;
	for(int i = 0; i < 4; ++i)
	{
		ret += dfs(row + delta[i][0], col + delta[i][1]);
	}
	return ret;
}

int main(void)
{
    cin>>N;
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    
    vector<int> result;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            int houseCount = dfs(i, j);
            if(houseCount != 0)
            {
                result.push_back(houseCount);
            }
        }
    }
    
    sort(result.begin(), result.end());
    cout<<result.size()<<endl;
    for(auto iter = result.begin(); iter < result.end(); ++iter)
    {
        cout<<*iter<<'\n';
    }
    
    return 0;
}
