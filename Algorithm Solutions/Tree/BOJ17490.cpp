#include <iostream>
#include <climits>

using namespace std;

const int MAXN = 1'000'001;
int S[MAXN];
bool bBlocked[MAXN];

int parent[MAXN];

int find(int node)
{
    if(node == parent[node]) {
        return node;
    }
    
    return parent[node] = find(parent[node]);
}

void unite(int a, int b)
{
    parent[find(b)] = find(a);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < MAXN; ++i) { parent[i] = i; }
    
    int N, M;
    long long K;
    cin >> N >> M >> K;
    
    for(int i = 1; i <= N; ++i) {
        cin >> S[i];
    }
    S[0] = INT_MAX;
    
    for(int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        
        if(tmp1 > tmp2) {
    	    int tmp3 = tmp1;
    	    tmp1 = tmp2;
    	    tmp2 = tmp3;
		}
		
        if(tmp1 == 1 && tmp2 == N) {
        	tmp2 = 1;
		}
        
        bBlocked[tmp2] = true;
    }
    
    if(M == 1 || M == 0) {
    	cout << "YES" << endl;
    	return 0;
	}
    
    for(int i = 1; i <= N; ++i) {
        if(bBlocked[i]) {
            continue;
        }
        unite(i-1, i);
    }
    
    unite(1, 0);
    if(!bBlocked[1]) {
        unite(N, 1);
    }
    
    long long need = 0;
    int start = find(1);
    int prior = start;
    int minValue = INT_MAX;
    
    for(int i = 0; i < N+2; ++i) {
        int now = (start + i) % (N+1);
        
        if(find(now) != prior) {
            need += minValue;
    		//cout << now << ' ' << need << endl;
            prior = find(now);
            minValue = INT_MAX;
        }
        
        minValue = S[now] < minValue ? S[now] : minValue;
    }
    
	//out << need << endl;
    string result = K >= need ? "YES" : "NO";
    cout << result << endl;
    
    return 0;
}
