#include "WithdrawException.h"
#include "MiniBankingCommonDecl.h"


WithdrawException::WithdrawException(int money) : balance(money)
{}
void  WithdrawException::ShowExceptionReason()
{
	cout << "�޼��� : �ܾ� " << balance << ", �ܾ׺���!!" << endl;
}
