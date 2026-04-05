#include <cstring>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <utility>

using namespace std;

struct RESULT_E
{
    int success;
    char locname[5];
};

struct RESULT_S
{
    int cnt;
    char carlist[5][8];
};

struct Car {
    int enterAt;
    int zone;
    int slot;
    bool isTowed;
    int towedAt;
};

map<string, Car> cars;

int n, m, l;
set<int> emptySlotIdx[26];
queue<pair<int, string>> towQ;

void init(int N, int M, int L)
{
    n = N;
    m = M;
    l = L;

    for (int i = 0; i < N; ++i) {
        emptySlotIdx[i].clear();

        for (int j = 0; j < M; ++j) {
            emptySlotIdx[i].insert(j);
        }
    }

    cars.clear();

    while (!towQ.empty()) {
        towQ.pop();
    }

    return;
}

RESULT_E enter(int mTime, char mCarNo[])
{
    processTow(mTime);

    RESULT_E res_e;

    string carNoStr = string(mCarNo);
    if (cars.count(carNoStr) && cars[carNoStr].isTowed) {
        cars.erase(carNoStr);
    }

    int maxZone = -1;
    int maxEmptySpace = 0;

    for (int i = 0; i < n; ++i) {
        if (emptySlotIdx[i].size() > maxEmptySpace) {
            maxZone = i;
            maxEmptySpace = emptySlotIdx[i].size();
        }
    }

    if (maxEmptySpace == 0) {
        res_e.success = 0;
        return res_e;
    }

    int slotIdx = *emptySlotIdx[maxZone].begin();
    emptySlotIdx[maxZone].erase(slotIdx);
    
    Car car;
    car.enterAt = mTime;
    car.zone = maxZone;
    car.slot = slotIdx;
    car.towedAt = -1;
    car.isTowed = false;
    cars[carNoStr] = car;

    res_e.success = 1;
    toLocname(maxZone, slotIdx, res_e.locname);

    return res_e;
}

int pullout(int mTime, char mCarNo[])
{
    
}

RESULT_S search(int mTime, char mStr[])
{
    RESULT_S res_s;

    res_s.cnt = -1;

    return res_s;
}

void toLocname(int zone, int slot, char* locname) {
    locname[0] = zone + 'A';
    locname[1] = '0' + slot / 100;
    locname[2] = '0' + (slot % 100) / 10;
    locname[3] = '0' + slot % 10;
    locname[4] = 0;
}

void processTow(int curTime) {
    while (!towQ.empty() && towQ.front().first <= curTime) {
        int when = towQ.front().first;
        string carNo = towQ.front().second;
        towQ.pop();

        if (cars.count(carNo) && !cars[carNo].isTowed) {
            
        }
    }
}