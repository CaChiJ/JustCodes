#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;
int inputs[MAXN];

int GCD(int a, int b)
{ 
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
    
    for(int i = 0; i < N; ++i)
    {
        cin>>inputs[i];
    }
    
    sort(inputs, inputs + N);
    int res = inputs[1] - inputs[0];
    
    for(int i = 1; i < N - 1; ++i)
    {
        res = GCD(res, inputs[i + 1] - inputs[i]);
    }
    
    for(int i = 2; i <= res / 2; ++i)
    {
        if(res % i == 0)
        {
            cout<<i<<' ';
        }
    }
    
    cout<<res<<endl;
    
    return 0;
}
