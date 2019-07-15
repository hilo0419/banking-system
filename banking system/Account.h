#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "String.h"
#include "DepositException.h"
#include "WithdrawException.h"

class Account
{
private:
	int num;
	int accID;	//°èÁÂ¹øÈ£
	int balance; //ÀÜ¾×
	String cusName; //°í°´¸í

public:
	Account(int num, int ID, int money, const String& myname);

	Account(const Account &copy);

	int GetID() const;

	int Getbalance() const;

	String Getname() const;

	int Getnum() const;

	virtual void Deposit(int money);

	void WithdrawMoney(int money);

	virtual ~Account();

};

#endif // !ACCOUNT_H
