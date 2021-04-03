#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int inputs[MAXN];

int main(void)
{
    int N;
    cin>>N;
    
    for(int i = 0; i < N; ++i)
    {
        cin>>inputs[i];
    }
    
    sort(inputs, inputs + N);
    
    int result = 0;
    int prior = 0;
    for(int i = 0; i < N; ++i)
    {
        result += prior + inputs[i];
        prior += inputs[i];
    }
    
    cout<<result<<endl;
    
    return 0;
}
