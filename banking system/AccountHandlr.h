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

	// 메뉴 출력
	void ShowMenu(void);

	void LoadAccount(void);

	// 보통예금계좌 개설
	void MakeNormalAccount(void);

	// 신용신뢰계좌 개설
	void MakeCreditAccount(void);

	// 입금
	void DepositMoney(void);

	// 출금
	void WithdrawMoney(void);

	// 잔액조회
	void ShowAllAccInfo(void);

	bool AccountCnt(void);

	~AccountHandler();
};

#endif // !ACCOUNTHANDLR_H
