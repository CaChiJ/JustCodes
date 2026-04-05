#include <cstring>
#include <map>
#include <string>
#include <set>

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

    return;
}

RESULT_E enter(int mTime, char mCarNo[])
{
    RESULT_E res_e;

    string carNoStr = string(mCarNo);

    int maxZone = -1;
    int maxEmptySpace = -1;

    for (int i = 0; i < 26; ++i) {
        if (emptySlotIdx[i].size() > maxEmptySpace) {
            maxZone = i;
            maxEmptySpace = emptySlotIdx[i].size();
        }
    }

    int slotIdx = *emptySlotIdx[maxZone].begin();
    emptySlotIdx[maxZone].erase(slotIdx);
    
    Car car;
    car.enterAt = mTime;
    car.zone = maxZone;
    car.slot = slotIdx;
    car.towedAt = -1;
    car.isTowed = false;
    cars[mCarNo] = car;

    res_e.success = 1;
    toLocname(maxZone, slotIdx, res_e.locname);

    return res_e;
}

int pullout(int mTime, char mCarNo[])
{
    return -1;
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
    while (!)
}