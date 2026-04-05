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
		marked
		
		for (int col = 0; col < WIDTH; ++col) {
			int lastTile = -1;
			int length = 0;

			for (int row = 0; row < HEIGHT; ++row) {
				if (lastTile != tiles[row][col]) {
					length = 1;
					lastTile = tiles[row][col];
				} else {
					length++;

					if (3 <= length) {
						
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
				}
			}
		}

		if (canScore(tiles)) {
			return;
		}
	}
}

int mRet[5];
int* takeTurn()
{
	return mRet;
}



int calcScore(int x, int y, int dir, int mTiles[][WIDTH]) {
	for 
}