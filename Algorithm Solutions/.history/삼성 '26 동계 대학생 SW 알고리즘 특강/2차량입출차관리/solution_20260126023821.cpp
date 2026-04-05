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

int n, m, l;

void init(int N, int M, int L)
{
    n = N;
    m = M;
    l = L;
    return;
}

RESULT_E enter(int mTime, char mCarNo[])
{
    RESULT_E res_e;

    res_e.success = -1;

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
}