#include "AccountHandlr.h"
#include "MiniBankingCommonDecl.h"
#include "AccountHandlr.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "MiniBankingCommonDecl.h"
#include <fstream>

// 메뉴용 열거자
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };

int main(void)
{
	AccountHandler bank;

	bank.LoadAccount();

	int choice;


	while (1)
	{
		bank.ShowMenu();

		cout<<"  "<< "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			int account;
		case MAKE:
			if (!bank.AccountCnt())
				break;
			cout<<"  "<< "[계좌종류선택]" << endl;
			cout<<"  "<< "1. 보통예금계좌 " << " 2. 신용신뢰계좌" << endl;
			cout << endl;
			cout<<"  "<< "선택 : ";
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
				cout << "없는 메뉴입니다. 다시 선택해주세요." << endl << endl;
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
			cout << "없는 메뉴입니다. 다시 선택해주세요." << endl << endl;
		}
	}

	return 0;
}