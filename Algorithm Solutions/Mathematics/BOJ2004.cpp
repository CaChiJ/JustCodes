#include <iostream>

using namespace std;

int countK(int n, int k)
{
    int ret = 0;
    
    while(n > 1)
    {
        n /= k;
        ret += n;
    }
    
    return ret;
}

int main(void)
{
    int n, m;
    cin>>n>>m;
    
    int result = min(countK(n, 2) - countK(n - m, 2) - countK(m, 2), countK(n, 5) - countK(n - m, 5) - countK(m, 5));
    
    cout<<max(result, 0)<<endl;
    
    return 0;
}
