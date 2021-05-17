#include <iostream>

using namespace std;

int parent[1000001];

int find(int node) {
    if(node == parent[node])
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
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < 1000001; ++i) { parent[i] = i; }
    int n, m;
    cin>>n>>m;
    
    for(int i = 0; i < m; ++i)
    {
        int op, a, b;
        cin>>op>>a>>b;
        
        switch(op)
        {
		case 0:
            uni(a, b);
            break;
        case 1:
            string result = find(a) == find(b) ? "YES" : "NO";
            cout << result << '\n';
            break;   
		}
    }
    
    return 0;
}
