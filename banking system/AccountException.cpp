#include "AccountException.h"
#include "MiniBankingCommonDecl.h"

AccountException::AccountException(int cnt) : AccountCnt(cnt)
{}

void AccountException::ShowExceptionReason()
{
	cout << "�޼��� : " << AccountCnt << "�̻� ���°��� �Ұ�!!" << endl;
	getchar();
	getchar();

}