#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;
vector<int> edges[MAXN + 1];
bool visited[MAXN + 1];

int dfs(int now)
{
    if(visited[now])
    {
        return 0;
    }
    
    visited[now] = true;
    int ret = 1;
    
    for(int i = 0; i < edges[now].size(); ++i)
    {
        ret += dfs(edges[now][i]);
    }
    
    return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int n;
    cin>>n;
    
    int edgeCount;
    cin>>edgeCount;
    
    for(int i = 0; i < edgeCount; ++i)
    {
        int a;
        int b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    cout<<dfs(1) - 1<<endl;
    
    return 0;
}
