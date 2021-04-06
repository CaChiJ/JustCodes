#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 1000000;
pair<int, int> X[MAXN];

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    for(int i = 0; i < N; ++i)
    {
        cin>>X[i].first;
        X[i].second = i;
    }
    
    sort(X, X + N);
    
    int newPos = 0;
    
    X[N].first = INT_MAX;
    
    for(int i = 0; i < N; ++i)
    {
    	int tmp = X[i].first;
    	X[i].first = newPos;
    	
    	if(tmp != X[i + 1].first)
    	{
    		++newPos;
		}
    }
    
    sort(X, X + N, comp);
    
    for(int i = 0; i < N; ++i)
    {
        cout<<X[i].first<<' ';
    }
    
    cout<<endl;
    
    return 0;
}
