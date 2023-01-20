#include <iostream>


enum DIRECTION
{
    TOP = 0,
    EAST = 1,
    WEST = 2,
    NORTH = 3,
    SOUTH = 4,
    BOTTOM = 5,
};

class Dice
{
private:
    int values[6] = {0, };

    const DIRECTION nextDirection[6][6] = {
        {TOP, EAST, WEST, NORTH, SOUTH, BOTTOM},
        {EAST, BOTTOM, TOP, NORTH, SOUTH, WEST},
        {WEST, TOP, BOTTOM, NORTH, SOUTH, EAST},
        {NORTH, EAST, WEST, BOTTOM, TOP, SOUTH},
        {SOUTH, EAST, WEST, TOP, BOTTOM, NORTH},
        {TOP, EAST, WEST, NORTH, SOUTH, BOTTOM},
    };

public:
    const int NONE = 0;

    int getValue(DIRECTION direction) {
        return values[direction];
    }

    void setValue(DIRECTION direction, int value) {
        values[direction] = value;
    }

    void roll(DIRECTION direction) {
        int rolledValues[6];

        for (int i = 0; i < 6; ++i) {
            rolledValues[nextDirection[direction][i]] = values[i];
        }

        for (int i = 0; i < 6; ++i) {
            values[i] = rolledValues[i];
        }
    }

    void print() {
        for (int i = 0; i < 6; ++i) {
            std::cout << values[i] << ' ';
        }

        std::cout << '\n';
    }
};

const int MAX_N = 20;
const int MAX_M = 20;

const int STEP[4][2] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
};

int main() {
    int N, M, x, y, K;
    std::cin >> N >> M >> x >> y >> K;

    int map[MAX_N][MAX_M] = {0, };

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            scanf("%d", &(map[r][c]));
        }
    }

    Dice dice;

    int rowIdx = x;
    int colIdx = y;

    for (int commandCount = 0; commandCount < K; ++commandCount) {
        int command;
        scanf("%1d", &command);

        int newRowIdx = rowIdx + STEP[command - 1][0];
        int newColIdx = colIdx + STEP[command - 1][1];

        if (newRowIdx < 0 || N <= newRowIdx || newColIdx < 0 || M <= newColIdx) {
            continue;
        }

        rowIdx = newRowIdx;
        colIdx = newColIdx;

        dice.roll(static_cast<DIRECTION>(command));

        if (map[rowIdx][colIdx] == 0) {
            map[rowIdx][colIdx] = dice.getValue(BOTTOM);
        } else {
            dice.setValue(BOTTOM, map[rowIdx][colIdx]);
            map[rowIdx][colIdx] = 0;
        }

        std::cout << dice.getValue(TOP) << '\n';

        // dice.print();
    }

    return 0;
}