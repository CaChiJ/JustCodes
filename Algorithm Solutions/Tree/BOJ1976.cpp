#include <iostream>

using namespace std;

int parent[201];

int find(int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void uni(int a, int b)
{
    parent[find(b)] = find(a);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < 201; ++i) { parent[i] = i; }
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
        	//cout << i << ' '<< j <<'\n';
            int tmp;
            cin>>tmp;
            
            if(tmp == 1)
            {
                uni(i+1, j+1);
            }
        }
    }
    
    int tmp;
    cin >> tmp;
    int root = find(tmp);
    bool result = true;
    for(int i = 0; i < M-1; ++i)
    {
        int city;
        cin>>city;
        
        if(root != find(city))
        {
            result = false;
            break;
        }
    }
    
    string output = result ? "YES" : "NO";
    cout << output << endl;
    
    return 0;
}
