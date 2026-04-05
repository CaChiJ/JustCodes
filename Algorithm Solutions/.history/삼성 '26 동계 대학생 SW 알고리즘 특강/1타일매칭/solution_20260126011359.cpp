#include <cstring>

#define WIDTH (8)
#define HEIGHT (8)

int (*tiles)[WIDTH];
int qRowIdx[WIDTH];

void init(int N, int mTiles[][WIDTH])
{
	tiles = mTiles;

	for (int i = 0; i < WIDTH; ++i) {
		qRowIdx[i] = 8;
	}

	while (true) {
		int marking[HEIGHT][WIDTH];
		memset(marking, 0, sizeof(marking));
		
		for (int col = 0; col < WIDTH; ++col) {
			int lastTile = -1;
			int length = 0;

			for (int row = 0; row < HEIGHT; ++row) {
				if (lastTile != tiles[row][col]) {
					length = 1;
					lastTile = tiles[row][col];
				} else {
					length++;

					if (3 == length) {
						marking[row-2][col] = marking[row-1][col] = marking[row][col] = 1;
					} else if (3 < length) {
						marking[row][col] = 1;
					}
				}
			}
		}

		for (int row = 0; row < WIDTH; ++row) {
			int lastTile = -1;
			int length = 0;

			for (int col = 0; col < WIDTH; ++col) {
				if (lastTile != tiles[row][col]) {
					length = 1;
					lastTile = tiles[row][col];
				} else {
					length++;

					if (3 == length) {
						marking[row][col-2] = marking[row][col-1] = marking[row][col] = 1;
					} else if (3 < length) {
						marking[row][col] = 1;
					}
				}
			}
		}

		bool hasMarked = false;

		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				if (marking[i][j]) {
					remove(i, j);
					hasMarked = true;
				}
			}
		}

		if (!hasMarked && canScore()) {
			return;
		}
	}
}

int mRet[5];
int* takeTurn()
{


	return mRet;
}


int remove(int row, int col) {
	for (int i = row; i < HEIGHT - 1; ++i) {
		tiles[i][col] = tiles[i + 1][col];
	}

	tiles[HEIGHT-1][col] = tiles[qRowIdx[col]++][col];
}

bool canScore() {
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (calcScore(j, i, 0) + calcScore(j, i, 1) > 0) {
				return true;
			}
		}
	}

	return false;
}

// dir = {0(오른쪽), 1(위쪽)}
int calcScore(int x, int y, int dir) {
	for (int r = 0; r < WIDTH; ++r) {
		for (int c = 0; c < HEIGHT; ++c) {

		}
	}
}

void removeAll() {
	for (int row=0; row<HEIGHT; ++row) {
		for (int col=0; col<WIDTH; ++col) {
			tiles[HEIGHT-1][col] = tiles[qRowIdx[col]++][col];
		}
	}
}