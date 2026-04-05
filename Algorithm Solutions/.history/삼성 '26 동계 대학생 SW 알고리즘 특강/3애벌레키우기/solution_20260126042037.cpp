#include <deque>
#include <utility>

using namespace std;

const int UP=0;
const int RIGHT=1;
const int DOWN=2;
const int LEFT=3;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

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

    pair<int, int> headPos() {
        return make_pair(lines.back().x + lines.back().len * dx[lines.back().dir], lines.back().y + lines.back().len * dy[lines.back().dir]);
    }

    int length() {
        int len = 0;
        for (int i = 0; i < lines.size(); ++i) {
            len += lines[i].len;
        }
        return len;
    }
};

int n;
vector<Larva> larvas;
int currentTime;

void init(int N)
{
    n = N;
    currentTime = 0;
    larvas.clear();
}

void join(int mTime, int mID, int mX, int mY, int mLength)
{
    while(currentTime < mTime) {
        tick();
        currentTime++;
    }

    Larva larva;
    larva.id = mID;
    larva.headDir = UP;
    larva.poten = 0;
    Line line;
    line.dir = UP;
    line.len = mLength;
    line.x = mX + mLength - 1;
    line.y = mY;
    larva.lines.push_back(line);
    larvas.push_back(larva);
}

RESULT top5(int mTime)
{
    RESULT ret = RESULT();

    while(currentTime < mTime) {
        tick();
        currentTime++;
    }

    sort(larvas.begin(), larvas.end(), compLarva);

    int count = min(larvas.size(), 5);

    return ret;
}

void tick() {
    for (int i = 0; i < larvas.size(); ++i) {
        // 헤드 계산
        if (larvas[i].lines.size() == 1) {
            Line line;
            line.dir = (larvas[i].lines.back().dir + 1) % 4;
            line.len = 1;
            pair<int, int> head = larvas[i].headPos();
            line.x = head.first + dx[line.dir];
            line.y = head.second + dy[line.dir];
            larvas[i].lines.push_back(line);
        } else {
            larvas[i].lines.back().len++;
        }

        // 꼬리 계산
        if (larvas[i].poten > 0) {
            larvas[i].poten--;
        } else {
            larvas[i].lines.front().len--;
            if (larvas[i].lines.front().len == 0) {
                larvas[i].lines.pop_front();
            }
        }
    }

    vector<int> larvasToClear;

    for (int i = 0; i < larvas.size(); ++i) {
        pair<int, int> head = larvas[i].headPos();
        
        for (int j = 0; j < larvas.size(); ++j) {
            if (i == j) {
                continue;
            }

            for (int l = 0; l < larvas[j].lines.size(); ++l) {
                if (isConflicted(head.first, head.second, larvas[j].lines[l])) {
                    larvas[j].poten += larvas[i].length();
                    larvasToClear.push_back(i);
                    break;
                }
            }
        }
    }

    for (int idx: larvasToClear) {
        larvas[idx].lines.clear();
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

bool compLarva(Larva& a, Larva& b) {
    return a.length() >= b.length();
}