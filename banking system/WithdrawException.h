#ifndef WITHDRAWEXCEPTION_H
#define WITHDRAWEXCEPTION_H

class WithdrawException
{
private:
	int balance;
public:
	WithdrawException(int money);

	void ShowExceptionReason();

};

#endif // !WITHDRAWEXCEPTION_H

