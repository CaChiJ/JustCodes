#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define WIDTH (8)

const int CMD_INIT = 100;
const int CMD_TAKETURN = 200;

static int tiles[10000][WIDTH];

extern void init(int N, int mTiles[][WIDTH]);
extern int* takeTurn();

static bool run()
{
	bool okay = false;
	int Q, N;

	scanf("%d", &Q);

	for (int q = 0; q < Q; ++q)
	{
		int cmd;
		int correct_ans[5];
		int* user_ans;
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &N);
			for (int y = 0; y < N; y++)
			{
				for (int x = 0; x < WIDTH; x++)
				{
					scanf("%d", tiles[y] + x);
				}
			}

			init(N, tiles);
			okay = true;
			break;
		case CMD_TAKETURN:
			user_ans = takeTurn();
			for (int i = 0; i < 5; i++)
			{
				scanf("%d", correct_ans + i);
				if (user_ans[i] != correct_ans[i])
					okay = false;
			}
			break;
		default:
			okay = false;
			break;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int TC, MARK;

	scanf("%d %d", &TC, &MARK);
	for (int tc = 1; tc <= TC; ++tc)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}