#ifndef DEPSITEXCEPTION_H
#define DEPSITEXCEPTION_H

class DepositException
{
private:
	int depositMoney;
public:
	DepositException(int money);

	void ShowExceptionReason();
};

#endif // !DEPSITEXCEPTION_H
