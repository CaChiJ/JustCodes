#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if(a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    while(b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    int first;
    cin>>first;
    
    for(int i = 0; i < N - 1; ++i)
    {
        int ring;
        cin>>ring;
        
        int gcd = GCD(ring, first);
        cout<<first / gcd<<'/'<<ring / gcd<<'\n';
    }
    
    return 0;
}
