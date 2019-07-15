#include "WithdrawException.h"
#include "MiniBankingCommonDecl.h"


WithdrawException::WithdrawException(int money) : balance(money)
{}
void  WithdrawException::ShowExceptionReason()
{
	cout << "¸Þ¼¼Áö : ÀÜ¾× " << balance << ", ÀÜ¾×ºÎÁ·!!" << endl;
}
