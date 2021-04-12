#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin>>TC;
    
    for(int tcCnt = 0; tcCnt < TC; ++tcCnt)
    {
        int c;
        cin>>c;
        
        map<string, int> dressCount;
        
        for(int i = 0; i < c; ++i)
        {
            string name, type;
            cin>>name>>type;
            
            ++dressCount[type];
        }
        
        int ret = 1;
        
        for(auto i = dressCount.begin(); i != dressCount.end(); ++i)
        {
            ret *= (*i).second + 1;
        }
        
        ret -= 1;
        cout<<ret<<'\n';
    }
    
    return 0;
}
