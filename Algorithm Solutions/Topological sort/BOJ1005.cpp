#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct
{
    int number;
    int topology;
    int takenTime;
    vector<int> nodes;
} Building;

struct compare
{
    bool operator()(Building &a, Building &b)
	{
        return a.takenTime > b.takenTime;
    }
};

int main(void) {
    int T;
    cin >> T;
    
    for(int tcCnt = 0; tcCnt < T; ++tcCnt) {
        int N, K;
        cin >> N >> K;
        
        vector<Building> buildings(N);
        
        for(int i = 0; i < N; ++i) {
            cin >> buildings[i].takenTime;
            buildings[i].topology = 0;
            buildings[i].number = i;
        }
        
        for(int i = 0; i < K; ++i) {
            int from, to;
            cin >> from >> to;
            
            buildings[from-1].nodes.push_back(to-1);
            buildings[to-1].topology++;
        }
        
        int W;
        cin >> W;
        W--;
        
        int time = 0;
        priority_queue<Building, vector<Building>, compare> pq;
        
        bool flag = true;
        
        while(flag) {
            for(int i = 0; i < N; ++i) {
                if(buildings[i].topology == 0) {
                    buildings[i].topology = -1;
                    buildings[i].takenTime += time;
                    pq.push(buildings[i]);
                }
            }
            
            do {
            	Building now = pq.top();
            	pq.pop();
            	time = now.takenTime;
            	
            	if(now.number == W) {
            		cout << time << '\n';
            		flag = false;
            		break;
				}
            	
            	for(auto i = now.nodes.begin(); i < now.nodes.end(); ++i) {
                	buildings[*i].topology--;
            	}
			} while(!pq.empty() && pq.top().takenTime == time);
            
            
            
        }
    }
    
    return 0;
}
