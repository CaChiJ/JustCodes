#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    cin>>a>>b;
    
    int smaller = a < b ? a : b;
    int greater = a > b ? a : b;
    
    int gcf = -1;
    for(int i = smaller; i > 0; --i)
    {
        if(a % i == 0 && b % i == 0)
        {
            gcf = i;
            break;
        }
    }
    
    int lcm = -1;
    for(int i = greater; i <= smaller * greater; ++i)
    {
        if(i % greater == 0 && i % smaller == 0)
        {
            lcm = i;
            break;
        }
    }
    
    cout<<gcf<<'\n'<<lcm<<endl;
    
    return 0;
}
