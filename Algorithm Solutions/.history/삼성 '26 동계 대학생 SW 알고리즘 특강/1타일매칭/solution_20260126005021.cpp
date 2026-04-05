#define WIDTH (8)
#define HEIGHT (8)

int (*tiles)[WIDTH];
int queuedRow[WIDTH];

void init(int N, int mTiles[][WIDTH])
{
	tiles = mTiles;

	while (true) {
		// 즉시 점수는 제거

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


bool canScore(int mTiles[][WIDTH]) {
	
}