#include <iostream>

using namespace std;

const int MAX_N = 1'000'001;
int parent[MAX_N];
int width[MAX_N];

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
    width[find(a)] += width[find(b)];
    parent[find(b)] = find(a);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i <= N; ++i) {
        parent[i] = i;
        width[i] = 1;
    }
    
    for(int i = 0; i < M; ++i)
    {
        int x, y;
        cin >> x >> y;
        int root_x = find(x);
        
        for(int room = root_x+width[root_x]; room <= y; room += width[room])
        {
            uni(root_x, room);
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= N; i += width[i])
    {
        answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}
