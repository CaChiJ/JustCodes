#include <iostream>
#include <vector>

using namespace std;

bool lamps[55][55];
int leftLamp[55];
int parent[55];

int find(int a) {
    if(parent[a] == a) {
        return a;
    }
    
    return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
    parent[find(b)] = find(a);
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < 55; ++i) {
        parent[i] = i;
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            int lamp;
            scanf("%1d", &lamp);
            
            if(lamp == 1) {
                lamps[i][j] = true;
            } else {
                ++leftLamp[i];
            }
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = i+1; j < N; ++j) {
            if(leftLamp[i] != leftLamp[j] || find(i) == find(j)) {
                continue;
            }
            
            bool isSame = true;
            
            for(int k = 0; k < M; ++k) {
                if(lamps[i][k] != lamps[j][k]) {
                    isSame = false;
                    break;
                }
            }
            
            if(isSame) {
                uni(i, j);
            }
        }
    }
    
    vector<int> v;
               
    for(int i = 0; i < N; ++i) {
        if(parent[i] == i) {
            v.push_back(i);
        }
    }
               
    int K;
    cin >> K;
    
    int result = 0;
    
    for(auto iter = v.begin(); iter < v.end(); ++iter) {
        if(leftLamp[*iter] <= K && leftLamp[*iter] % 2 == K % 2) {
        	int count = 1;
            
			for(int i = 0; i < N; ++i) {
                if(*iter == i) {
                	continue;
				}
				
                if(find(*iter) == find(i)) {
                    ++count;
                }
            }
                
            result = max(result, count);
        }
    }
    
    cout << result << endl;
    
    return 0;
}
