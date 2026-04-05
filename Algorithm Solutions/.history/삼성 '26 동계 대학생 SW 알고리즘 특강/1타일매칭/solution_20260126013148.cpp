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

		for (int col = 0; col < WIDTH; ++col) {
			int curRow = 0;

			for (int row = 0; row < HEIGHT; ++row) {
				if (marking[row][col]) {
					hasMarked = true;
					continue;
				}

				tiles[curRow++][col] = tiles[row][col];
			}

			while (curRow < HEIGHT) {
				tiles[curRow++][col] = tiles[qRowIdx[col]++][col];
			}
		}

		if (!hasMarked) {
			if (canScore()) {
				return;
			}

			removeAll();
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
int calcScore(int col, int row, int dir) {
	int dr, dc;
	if (dir == 0) {
		dc++;
	} else if (dir == 1) {
		dr++;
	}

	int col2 = col + dc;
	int row2 = row + dr;

	if (row2 >= HEIGHT || col2 >= WIDTH) {
		return 0;
	}

	int tmp = tiles[row][col];
	tiles[row][col] = tiles[row2][col2];
	tiles[row2][col2] = tmp;

	int* outLeft1;
	int* outRight1;
	calcHorizontalCount(row, col, outLeft, outRight);


}

int calcHorizontalCount(int row, int col, int* outLeft, int* outRight) {
	int tile = tiles[row][col];
	*outLeft = *outRight = col;

	for (int c = col-1; c >= 0; --c) {
		if (tiles[row][c] != tile) {
			break;
		}

		*outLeft = c;
	}

	for (int c = col+1; c < WIDTH; ++c) {
		if (tiles[row][c] != tile) {
			break;
		}

		*outRight = c;
	}

	return *outRight - *outLeft + 1;
}

void removeAll() {
	for (int row=0; row<HEIGHT; ++row) {
		for (int col=0; col<WIDTH; ++col) {
			tiles[row][col] = tiles[qRowIdx[col]++][col];
		}
	}
}