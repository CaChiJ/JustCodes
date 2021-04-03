#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    string input;
    cin>>input;
    input = input + '-';
    
    bool first = true;
    int result = 0;
    int tmp = 0;
    
    for(auto i = input.begin(); i < input.end(); ++i)
    {
        int num = 0;
        
        do
        {
            num *= 10;
            num += *i - 48;
            ++i;
            
            if(i == input.end())
			{
				break;
			} 
        } while(*i != '+' && *i != '-');
        
        tmp += num;
        
        if(*i == '-')
        {
            if(first)
			{
				result += tmp;
				first = false;
			}
            else
			{
				result -= tmp;
			}
			
			tmp = 0;
        }
    }
    
    cout<<result<<endl;
    return 0;
}
