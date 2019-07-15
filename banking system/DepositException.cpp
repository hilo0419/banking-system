#include "DepositException.h"
#include "MiniBankingCommonDecl.h"


DepositException::DepositException(int money) : depositMoney(money)
{}
void DepositException::ShowExceptionReason()
{
	cout << "메세지 : " << depositMoney << "는 입금불가!!" << endl;
}
