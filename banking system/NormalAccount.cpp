#include "NormalAccount.h"
#include <fstream>


NormalAccount::NormalAccount(int num, int ID, int money, const String& myname, int rate)
	:Account(num, ID, money, myname), interestRate(rate)
{}

void NormalAccount::Deposit(int money)
{
	Account::Deposit(money);
	Account::Deposit(money*(interestRate) / 100.0);
}

NormalAccount::~NormalAccount() {

	ofstream fout("AccountList.txt", ios::app);

	fout << interestRate;

	fout.close();

}
