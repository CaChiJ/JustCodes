#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
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
    
    int lcm = a * b / gcf;
    
    cout<<gcf<<'\n'<<lcm<<endl;
    
    return 0;
}
