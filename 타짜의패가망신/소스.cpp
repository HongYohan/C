#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int times() {
	int nSel;
	printf("�������� �Ͻðڽ��ϱ�? ");
	do {
		printf("(1���� ū �ڿ���) >> ");
		scanf_s("%d", &nSel);
	} while (nSel < 2);
	return nSel;
}

int bet_money() {
	int bet;
	printf("�󸶸� �����Ͻǰǰ���? ");
	do {
		printf("(0���� ũ��) >> ");
		scanf_s("%d", &bet);
	} while (bet < 1);
	return bet;
}
int my_num(int nSel) {
	printf("1~%d �߿� ���ڸ� �ϳ� �Է��ϼ��� ", nSel);
	int sel;
	do {
		printf("(0: ����δ��� �ʰ� ������ �׸��д�.) >> ");
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
		printf("\n���߿� ������ �׸��νŴٴ�... �������� ����� �����ó׿�.\n");
	}
	else if (mGambler == 0) {
		printf("\n����� ������ ����� ���׿�?\n");
	}
	else {
		printf("\n�۷ι� ī���� ������Ʈ�� ��ϵǼ̽��ϴ�. �����մϴ�.\n");
	}
}

void result_1(int mCasino, int mGambler,int nSel) {
	int sel=0;
	while (mCasino > 0 && mGambler > 0) {
		printf("\n���� ����\nī����: %d��, YOU: %d\n", mCasino, mGambler);
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
		printf("\n���� ����\nī����: %d��, YOU: %d\n\n", mCasino, mGambler);
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