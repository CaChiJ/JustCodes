#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int moded = a % b;
    
    if(moded == 0)
    {
        return b;
    }
    
    return gcd(b, moded);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin>>TC;
    
    for(int tcCnt = 0; tcCnt < TC; ++tcCnt)
    {
        int a, b;
        cin>>a>>b;
        
        cout<<a * b / gcd(a, b)<<'\n';
    }
    
    cout<<endl;
    
    return 0;
}
