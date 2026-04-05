#include <deque>
#include <utility>

using namespace std;

const int UP=0;
const int RIGHT=1;
const int DOWN=2;
const int LEFT=3;

struct RESULT
{
    int cnt = 0;
    int IDs[5] = {0, 0, 0, 0, 0};
};

struct Line {
    int x, y;
    int dir;
    int len;
};

struct Larva {
    int id;
    int headDir;
    int poten;
    deque<Line> lines;
};

int n;
vector<Larva> larvas;

void init(int N)
{
    n = N;
}

void join(int mTime, int mID, int mX, int mY, int mLength)
{

}

RESULT top5(int mTime)
{
    RESULT ret = RESULT();
    return ret; // dummy
}

void tick() {
    for (int i = 0; )
}

bool isConflicted(int x, int y, Line line) {
    if (line.dir == UP || line.dir == DOWN) {
        int y2 = y + (line.dir == UP ? -line.len : line.len);
    }
}