#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int N, M, V;
vector<int> edge[MAXN + 1];
vector<bool> visited(MAXN + 1);

void dfs(int v)
{
    visited[v] = true;
	cout<<v<<' ';
    
    for(int i = 0; i < edge[v].size(); ++i)
    {
        if(!visited[edge[v][i]])
        {
        	dfs(edge[v][i]);
        }
    }
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	
	while(!q.empty())
	{
		int node = q.front();
		cout<< node <<' ';
		q.pop();
		
		for(int i = 0; i < edge[node].size(); ++i)
		{
			if(!visited[edge[node][i]])
			{
				q.push(edge[node][i]);
				visited[edge[node][i]] = true;
			}
		}
	}
	
}


int main(void)
{
    cin>>N>>M>>V;
    
    for(int i = 0; i < M; ++i)
    {
        int from, to;
        cin>>from>>to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    
    for(int i = 0 ; i <= N; ++i)
    {
    	sort(edge[i].begin(), edge[i].end());
	}
    
    dfs(V);
    cout<<endl;
    
    for(int i = 0; i <= N; ++i)
    {
    	visited[i] = false;
	}
	
	bfs(V);
    cout<<endl;
    
    return 0;
}
