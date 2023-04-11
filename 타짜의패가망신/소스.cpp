#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int times() {
	int nSel;
	printf("몇지선다 하시겠습니까? ");
	do {
		printf("(1보다 큰 자연수) >> ");
		scanf_s("%d", &nSel);
	} while (nSel < 2);
	return nSel;
}

int bet_money() {
	int bet;
	printf("얼마를 베팅하실건가요? ");
	do {
		printf("(0보다 크게) >> ");
		scanf_s("%d", &bet);
	} while (bet < 1);
	return bet;
}
int my_num(int nSel) {
	printf("1~%d 중에 숫자를 하나 입력하세요 ", nSel);
	int sel;
	do {
		printf("(0: 대장부답지 않게 게임을 그만둔다.) >> ");
		scanf_s("%d", &sel);
	} while (sel < 0 || sel > nSel);
	return sel;
}
int casino_num(int nSel) {
	srand((unsigned int)time(NULL));
	int ans=rand() % nSel + 1;
	return ans;
}

void stop_1(int sel, int mGambler) {
	if (sel == 0) {
		printf("\n도중에 갬블을 그만두신다니... 정말이지 대단한 의지시네요.\n");
	}
	else if (mGambler == 0) {
		printf("\n당신은 갬블에는 재능이 없네요?\n");
	}
	else {
		printf("\n글로벌 카지노 블랙리스트에 등록되셨습니다. 축하합니다.\n");
	}
}

void result_1(int mCasino, int mGambler,int nSel) {
	int sel=0;
	while (mCasino > 0 && mGambler > 0) {
		printf("\n게임 시작\n카지노: %d원, YOU: %d\n", mCasino, mGambler);
		int bet = bet_money();
		sel = my_num(nSel);
		int ans = casino_num(nSel);

		if (sel == 0) {
			break;
		}
		if (ans == sel) {
			mGambler += bet * nSel;
			mCasino -= bet * nSel;
		}
		else {
			mGambler -= bet;
			mCasino += bet;
		}
		printf("\n게임 종료\n카지노: %d원, YOU: %d\n\n", mCasino, mGambler);
	}
	stop_1(sel, mGambler);
}



int main() {
	int mCasino = 1234567890,
		mGambler = 100;
	int nSel = times();
	result_1(mCasino, mGambler,nSel);
	
	system("pause");
	return 0;
}