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
		markSequence(marking);

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
	int maxScore = -1;
	int maxRow = -1;
	int maxCol = -1;
	int maxDir = -1;

	for (int row = 0; row < HEIGHT; ++row) {
		for (int col = 0; col < WIDTH; ++col) {
			int score1 = calcScore(col, row, 0);
			int score2 = calcScore(col, row, 1);

			if (maxScore < score1) {
				maxScore = score1;
				maxRow = row;
				maxCol = col;
				maxDir = 0;
			}

			if (maxScore < score2) {
				maxScore = score2;
				maxRow = row;
				maxCol = col;
				maxDir = 1;
			}
		}
	}

	int scoreSum = maxScore;
	mRet[1] = maxRow;
	mRet[2] = maxCol;
	mRet[3] = maxRow + (maxDir ? 1 : 0);
	mRet[4] = maxCol + (maxDir ? 0 : 1);

	// swap
	int tmp = tiles[maxRow][maxCol];
	tiles[maxRow][maxCol] = tiles[mRet[3]][mRet[4]];
	tiles[mRet[3]][mRet[4]] = tmp;

	int marking[HEIGHT][WIDTH];
	memset(marking, 0, sizeof(marking));

	int outLeft1, outRight1;
	int horCount1 = calcHorizontalCount(mRet[1], mRet[2], &outLeft1, &outRight1);

	int outLeft2, outRight2;
	int horCount2 = calcHorizontalCount(mRet[1], mRet[2], &outLeft2, &outRight2);

	int outTop1, outBottom1;
	int verCount1 = calcVerticalCount(mRet[3], mRet[4], &outTop1, &outBottom1);

	int outTop2, outBottom2;
	int verCount2 = calcVerticalCount(mRet[3], mRet[4], &outTop2, &outBottom2);

	mRet[0] = scoreSum;

	return mRet;
}


// int remove(int row, int col) {
// 	for (int i = row; i < HEIGHT - 1; ++i) {
// 		tiles[i][col] = tiles[i + 1][col];
// 	}

// 	tiles[HEIGHT-1][col] = tiles[qRowIdx[col]++][col];
// }

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
	int dr = 0;
	int dc = 0;
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

	if (tiles[row][col] == tiles[row2][col2]) {
		return 0;
	}

	// swap
	int tmp = tiles[row][col];
	tiles[row][col] = tiles[row2][col2];
	tiles[row2][col2] = tmp;

	int outLeft1, outRight1;
	int horCount1 = calcHorizontalCount(row, col, &outLeft1, &outRight1);

	int outLeft2, outRight2;
	int horCount2 = calcHorizontalCount(row2, col2, &outLeft2, &outRight2);

	int outTop1, outBottom1;
	int verCount1 = calcVerticalCount(row, col, &outTop1, &outBottom1);

	int outTop2, outBottom2;
	int verCount2 = calcVerticalCount(row2, col2, &outTop2, &outBottom2);

	int result = getScore(horCount1) + getScore(horCount2) + getScore(verCount1) + getScore(verCount2);
	
	// swap (복구))
	tmp = tiles[row][col];
	tiles[row][col] = tiles[row2][col2];
	tiles[row2][col2] = tmp;

	return result;
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

int calcVerticalCount(int row, int col, int* outBottom, int* outTop) {
	int tile = tiles[row][col];
	*outBottom = *outTop = row;

	for (int r = row-1; r >= 0; --r) {
		if (tiles[r][col] != tile) {
			break;
		}

		*outBottom = r;
	}

	for (int r = row+1; r < HEIGHT; ++r) {
		if (tiles[r][col] != tile) {
			break;
		}

		*outTop = r;
	}

	return *outTop - *outBottom + 1;
}

void removeAll() {
	for (int row=0; row<HEIGHT; ++row) {
		for (int col=0; col<WIDTH; ++col) {
			tiles[row][col] = tiles[qRowIdx[col]++][col];
		}
	}
}

int getScore(int count) {
	if (count < 3) {
		return 0;
	} else if (count == 3) {
		return 1;
	} else if (count == 4) {
		return 4;
	} else {
		return 9;
	}
}

void markSequence(bool (*marking)[HEIGHT]) {
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

		for (int col = 0; col < HEIGHT; ++col) {
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
}