#include "AccountHandlr.h"
#include "MiniBankingCommonDecl.h"
#include "AccountHandlr.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "MiniBankingCommonDecl.h"
#include <fstream>

// �޴��� ������
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//������ ����
enum { NORMAL = 1, CREDIT = 2 };

int main(void)
{
	AccountHandler bank;

	bank.LoadAccount();

	int choice;


	while (1)
	{
		bank.ShowMenu();

		cout<<"  "<< "���� : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			int account;
		case MAKE:
			if (!bank.AccountCnt())
				break;
			cout<<"  "<< "[������������]" << endl;
			cout<<"  "<< "1. ���뿹�ݰ��� " << " 2. �ſ�ŷڰ���" << endl;
			cout << endl;
			cout<<"  "<< "���� : ";
			cin >> account;
			cout << endl;
			switch (account)
			{
			case NORMAL:
				bank.MakeNormalAccount();
				break;
			case CREDIT:
				bank.MakeCreditAccount();
				break;
			default:
				cout << "���� �޴��Դϴ�. �ٽ� �������ּ���." << endl << endl;
			}
			break;
		case DEPOSIT:
			bank.DepositMoney();
			break;
		case WITHDRAW:
			bank.WithdrawMoney();
			break;
		case INQUIRE:
			bank.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "���� �޴��Դϴ�. �ٽ� �������ּ���." << endl << endl;
		}
	}

	return 0;
}