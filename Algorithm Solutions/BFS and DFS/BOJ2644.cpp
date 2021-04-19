#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100;
vector<int> connect[MAXN + 1];
int visit[MAXN + 1];

int bfs(int a, int b)
{
    queue<int> q;
    q.push(a);
    int dist = 1;
    
    while(!q.empty())
    {
        int qSize = q.size();
        for(int j = 0; j < qSize; ++j)
        {
            int now = q.front();
            q.pop();
            for(int i = 0; i < connect[now].size(); ++i)
            {
                if(!visit[connect[now][i]])
                {
                    if(connect[now][i] == b)
                    {
                        return dist;
                    }
                    
                    visit[connect[now][i]] = true;
                    q.push(connect[now][i]);
                }
            }
        }
        
        ++dist;
    }
    
    return -1;
}

int main(void)
{
    int N;
    cin>>N;
    
    int a, b;
    cin>>a>>b;
    
    int M;
    cin>>M;
    
    for(int i = 0; i < M; ++i)
    {
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        connect[tmp1].push_back(tmp2);
        connect[tmp2].push_back(tmp1);
    }
    
    cout<<bfs(a, b)<<endl;
    
    return 0;
}
