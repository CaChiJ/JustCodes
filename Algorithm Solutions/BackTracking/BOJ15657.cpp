#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 8;
int inputs[MAXN + 1];
vector<int> answer;

void getCount(int left, int nowIdx, int N)
{
    if(left == 0)
    {
        for(auto iter = answer.begin(); iter < answer.end(); ++iter)
        {
        	cout<<*iter<<' ';
		}
		cout<<'\n';
		return;
    }
    
    if(nowIdx == N)
    {
    	return;
    }
    
    int nextIdx = nowIdx + 1;
    answer.push_back(inputs[nowIdx]);
    getCount(left - 1, nowIdx, N);
    answer.pop_back();
    getCount(left, nextIdx, N);

    return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int M, N;
    cin>>N>>M;
    
    for(int i = 0; i < N; ++i)
    {
        cin>>inputs[i];
    }
    
    sort(inputs, inputs + N);
	getCount(M, 0, N);
    return 0;
}
