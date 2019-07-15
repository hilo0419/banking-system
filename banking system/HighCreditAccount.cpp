#include "HighCreditAccount.h"
#include <fstream>

//신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

HighCreditAccount::HighCreditAccount(int num, int ID, int money, const String& myname, int rate, int myclass)
	:Account(num, ID, money, myname), interestRate(rate), creditclass(myclass)
{}

void  HighCreditAccount::Deposit(int money)
{
	Account::Deposit(money);
	Account::Deposit(money*(interestRate / 100.0));

	if (creditclass == LEVEL_A)
	{
		Account::Deposit(money*(7 / 100.0));
	}
	else if (creditclass == LEVEL_B)
	{
		Account::Deposit(money*(4 / 100.0));
	}
	else if (creditclass == LEVEL_C)
	{
		Account::Deposit(money*(2 / 100.0));
	}
}

HighCreditAccount::~HighCreditAccount()
{

	ofstream fout("AccountList.txt", ios::app);
	fout << interestRate << ' ' << creditclass;

	fout.close();

}
