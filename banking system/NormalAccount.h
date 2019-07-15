#ifndef NORMALACCOUNT_H
#define NORMALACCOUNT_H

#include "Account.h"
#include "MiniBankingCommonDecl.h"
#include <fstream>

class NormalAccount : public Account
{
private:
	int interestRate;
public:
	NormalAccount(int num, int ID, int money, const String& myname, int rate);

	void Deposit(int money);

	~NormalAccount();

};

#endif // !NORMALACCOUNT_H

