#include "DepositException.h"
#include "MiniBankingCommonDecl.h"


DepositException::DepositException(int money) : depositMoney(money)
{}
void DepositException::ShowExceptionReason()
{
	cout << "�޼��� : " << depositMoney << "�� �ԱݺҰ�!!" << endl;
}
