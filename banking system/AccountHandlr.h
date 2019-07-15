#ifndef ACCOUNTHANDLR_H
#define ACCOUNTHANDLR_H

#include "Account.h"
#include "Array.h"
#include "AccountException.h"
#include <fstream>
#include "Array.cpp"

typedef Account * ACCOUNT_PTR;

class AccountHandler
{
private:
	Array<ACCOUNT_PTR> accArr;
	int accNum;
public:
	AccountHandler();

	// �޴� ���
	void ShowMenu(void);

	void LoadAccount(void);

	// ���뿹�ݰ��� ����
	void MakeNormalAccount(void);

	// �ſ�ŷڰ��� ����
	void MakeCreditAccount(void);

	// �Ա�
	void DepositMoney(void);

	// ���
	void WithdrawMoney(void);

	// �ܾ���ȸ
	void ShowAllAccInfo(void);

	bool AccountCnt(void);

	~AccountHandler();
};

#endif // !ACCOUNTHANDLR_H
