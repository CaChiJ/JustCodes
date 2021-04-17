#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100000;
int inputs[MAXN];

int LIS(int n)
{
    vector<int> v;
    
    for(int i = 0; i < n; ++i)
    {
        int left = 0;
        int right = v.size();
        while(left < right)
        {
            int mid = (left + right) / 2;
            
            if(v[mid] < inputs[i])
            {
                left = mid + 1;
            }
            else
            {
            	right = mid;
			}
        }
        
        if(v.size() > left)
        {
            v[left] = inputs[i];
        }
        else
        {
            v.push_back(inputs[i]);
        }
    }
    
    return v.size();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    
    int n;
    while(cin>>n)
    {	
        for(int i = 0; i < n; ++i)
        {
            cin>>inputs[i];
        }
        
        cout<<LIS(n)<<'\n';
    }
    
    return 0;
}
