#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e6;
pair<int, bool> T[2 * MAXN];

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    
    return a.first < b.first;
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
        int pos1 = 2 * i;
        int pos2 = 2 * i + 1;
        
        cin>>T[pos1].first>>T[pos2].first;
        //T[pos1].first = pos1 % 153276;
        //T[pos2].first = pos2 % 201769;
        
        T[pos1].second = true;
        T[pos2].second = false;
    }
    
    sort(T, T + 2 * N, comp);
    
    pair<int, int> range;
    int maxCount = -1;
    int count = 0;
    bool recorded = false;
    
    T[2 * N].first = -1;
    
    for(int i = 0; i < 2 * N; ++i)
    {
        if(T[i].second)
        {
            ++count;
            
            if(count > maxCount)
            {
                maxCount = count;
                range.first = T[i].first;
                recorded = true;
            }
        }
        else
        {
            --count;
            
            if(count < maxCount && recorded && T[i].first != T[i + 1].first)
            {
                range.second = T[i].first;
                recorded = false;
            }
        }
    }
    
    cout<<maxCount<<'\n'<<range.first<<' '<<range.second<<endl;
    
    return 0;
}
