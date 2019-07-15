#include "AccountException.h"
#include "MiniBankingCommonDecl.h"

AccountException::AccountException(int cnt) : AccountCnt(cnt)
{}

void AccountException::ShowExceptionReason()
{
	cout << "메세지 : " << AccountCnt << "이상 계좌개설 불가!!" << endl;
	getchar();
	getchar();

}