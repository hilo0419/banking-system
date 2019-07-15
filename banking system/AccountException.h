#ifndef ACCOUNTEXCEPTION_H
#define ACCOUNTEXCEPTION_H

#include "Exception.h"

class AccountException :public Exception
{
private:
	int AccountCnt;
public:
	AccountException(int cnt);

	void ShowExceptionReason();
};

#endif // !ACCOUNTEXCEPTION_H

