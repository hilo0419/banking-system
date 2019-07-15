#include "Account.h"
#include "MiniBankingCommonDecl.h"

#define _CRT_SECURE_NO_WARNINGS

Account::Account(int num, int ID, int money, const String& myname) : accID(ID), balance(money)
{
	this->num = num;
	this->cusName = myname;
}

Account::Account(const Account &copy)
	:accID(copy.accID), balance(copy.balance)
{
	this->num = copy.num;
	this->cusName = copy.cusName;
}

int Account::GetID() const
{
	return accID;
}

int Account::Getbalance() const
{
	return balance;
}

String Account::Getname() const
{
	return cusName;
}

int Account::Getnum() const
{
	return num;
}

void Account::Deposit(int money)
{
	if (money < 0)
	{
		//throw 발생 => exception class
		DepositException expn(money);
		throw expn;
	}
	balance += money;
}

void Account::WithdrawMoney(int money)
{
	if (money > balance)
	{
		//throw 발생 => exception class
		WithdrawException expn(money);
		throw expn;
	}
	balance -= money;
}

Account::~Account()
{}

