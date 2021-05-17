#include <iostream>

using namespace std;

const int SIZE = 1'000'001;
int parent[SIZE];
int partCount[SIZE];

int find(int node)
{
    if(node == parent[node]) {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    
    if(ra == rb) {
        return;
    }
    
    partCount[ra] += partCount[rb];
    parent[rb] = ra;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < SIZE; ++i) {
        parent[i] = i;
        partCount[i] = 1;
    }
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        char order;
        cin >> order;
        
        switch(order) {
            case 'I':
                int a, b;
                cin >> a >> b;
                uni(a, b);
                break;
            case 'Q':
                int c;
                cin >> c;
                cout << partCount[find(c)] << '\n';
                break;
            default:
                cout << "ERROR! Undefined Input" << '\n';
        }
    }
    
    return 0;
}
