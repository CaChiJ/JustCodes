#include <iostream>
#include <vector>
#include <utility>
#include <climits>


using namespace std;


int N, M;
vector< pair<int, int> > shops;
vector< pair<int, int> > houses;
bool isSelected[13];


int CalcDist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}


int GetMinDist(int idx, int sel) {
    if(idx == shops.size()) {
        if(sel != M) {
            return INT_MAX;
        }
        
        // calculate minimum distance
        
        int result = 0;
        
        for(auto house = houses.begin(); house < houses.end(); ++house) {
        	int minDist = INT_MAX;
        	
            for(auto shop = shops.begin(); shop < shops.end(); ++shop) {		
            	if(isSelected[shop - shops.begin()]) {
                    minDist = min(minDist, CalcDist(*shop, *house));
                }
            }
            
        	result += minDist;
        }
        
        return result;
    }
    
    isSelected[idx] = true;
    int result = GetMinDist(idx + 1, sel + 1);
    isSelected[idx] = false;
    result = min(result, GetMinDist(idx + 1, sel));
    
    return result;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
        	int input;
            cin >> input;
            
            if(input == 1) {
                houses.push_back({i, j});
            } else if(input == 2) {
                shops.push_back({i, j});
            }
        }
    }
    
    cout << GetMinDist(0, 0) << '\n';
    
    return 0;
}
