#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 64;
int inputs[MAXN + 1][MAXN + 1];

string makeTree(int y1, int x1, int y2, int x2)
{
    if(y1 == y2 && x1 == x2)
    {
        return to_string(inputs[y1][x1]);
	}
    
    string subTree[4];
    subTree[0] = makeTree(y1, x1, y1 + (y2 - y1) / 2, x1 + (x2 - x1) / 2);
    subTree[1] = makeTree(y1, x1 + (x2 - x1) / 2 + 1, y1 + (y2 - y1) / 2, x2);
    subTree[2] = makeTree(y1 + (y2 - y1) / 2 + 1, x1, y2, x1 + (x2 - x1) / 2);
    subTree[3] = makeTree(y1 + (y2 - y1) / 2 + 1, x1 + (x2 - x1) / 2 + 1, y2, x2);
    
    bool isSame = true;
    
    for(int i = 1; i <= 3; ++i)
    {
        if(subTree[0] != subTree[i] || subTree[0][0] == '(')
        {
            isSame = false;
            break;
        }
    }
    
    if(isSame)
    {
        return subTree[0];
    }
    
    return "(" + subTree[0] + subTree[1] + subTree[2] + subTree[3] + ")";;
}

int main(void)
{
    int n;
    cin>>n;
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            scanf("%1d", &inputs[i][j]);
        }
    }
    
    cout<<makeTree(1, 1, n, n)<<endl;
}
