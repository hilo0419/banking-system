#ifndef HIGHCREDITACCOUNT_H
#define HIGHCREDITACCOUNT_H

#include "Account.h"
#include "MiniBankingCommonDecl.h"
#include <fstream>

class HighCreditAccount : public Account
{
private:
	int interestRate;
	int creditclass;
public:
	HighCreditAccount(int num, int ID, int money, const String& myname, int rate, int myclass);

	void Deposit(int money);

	~HighCreditAccount();
};

#endif // !HIGHCREDITACCOUNT_H
