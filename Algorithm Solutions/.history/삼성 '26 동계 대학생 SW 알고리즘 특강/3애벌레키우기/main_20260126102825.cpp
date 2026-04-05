#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT        100
#define CMD_JOIN        200
#define CMD_TOP5    	300

struct RESULT
{
	int cnt;
	int IDs[5];
};

extern void init(int N);
extern void join(int mTime, int mID, int mX, int mY, int mLength);
extern RESULT top5(int mTime);

static bool run()
{
	int Q;
	int N, mTime, mID, mX, mY, mLength;

	RESULT res;
	int ret = -1, cnt, ans;

	scanf("%d", &Q);

	bool okay = false;

	for (int q = 0; q < Q; ++q)
	{
		int cmd;
		scanf("%d", &cmd);
		switch(cmd)
		{
		case CMD_INIT:
            scanf("%d", &N);
			init(N);
			okay = true;
			break;
		case CMD_JOIN:
			scanf("%d %d %d %d %d", &mTime, &mID, &mX, &mY, &mLength);
			join(mTime, mID, mX, mY, mLength);
			break;
		case CMD_TOP5:
			scanf("%d", &mTime);
			res = top5(mTime);
			scanf("%d", &cnt);
			if (res.cnt != cnt)
				okay = false;
			for (int i = 0; i < cnt; ++i)
			{
				scanf("%d", &ans);
				if (res.IDs[i] != ans)
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
	// freopen("sample_input.txt", "r", stdin);

	int TC, MARK;

	scanf("%d %d", &TC, &MARK);
	for (int tc = 1; tc <= TC; ++tc)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}