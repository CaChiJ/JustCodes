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
    for (int i = 0; larvas.size(); ++i) {
        // 꼬리 계산
        if (larvas[i].poten > 0) {
            larvas[i].poten--;
        } else {
            larvas[i].lines.front().len--;
            if (larvas[i].lines.front().len == 0) {
                larvas[i].lines.pop_front();
            }
        }

        // 헤드 계산
        
        for (Line line: larva.lines) {

        }
    }
}

bool isConflicted(int x, int y, Line line) {
    if (line.dir == UP || line.dir == DOWN) {
        int y2 = line.y + (line.dir == UP ? -line.len : line.len);
        return x == line.x && y >= min(y2, line.y) && y <= max(y2, line.y);
    } else {
        int x2 = line.x + (line.dir == LEFT ? -line.len : line.len);
        return y == line.y && x >= min(x2, line.x) && y <= max(x2, line.x);
    }
}