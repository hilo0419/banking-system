#include "AccountHandlr.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "MiniBankingCommonDecl.h"
#include <fstream>

enum { NORMAL = 1, CREDIT = 2 };

AccountHandler::AccountHandler() :accNum(0)
{}

void AccountHandler::ShowMenu(void)
{
	system("cls");
	cout << endl;
	cout<<"  "<< "====== Menu ======" << endl;
	cout<< "  " << "1. 계좌개설" << endl;
	cout<< "  " << "2. 입    금" << endl;
	cout<< "  " << "3. 출    금" << endl;
	cout<< "  " << "4. 전체고객 잔액조회" << endl;
	cout<< "  " << "5. 종    료" << endl;
	cout << "  " << "==================" << endl;
	cout << endl;
}

void AccountHandler::LoadAccount(void)
{
	ifstream in("AccountList.txt");
	int num;

	int id;
	int balance;
	String name;
	int rate;
	int Accclass;


	if (in.is_open())
	{

		while (!in.eof())
		{
			in >> num;

			if (num == NORMAL)
			{
				in >> id;
				in >> balance;
				in >> name;
				in >> rate;

				accArr[accNum++] = new NormalAccount(num, id, balance, name, rate);

			}
			else if (num == CREDIT)
			{
				in >> id;
				in >> balance;
				in >> name;
				in >> rate;
				in >> Accclass;

				accArr[accNum++] = new HighCreditAccount(num, id, balance, name, rate, Accclass);

			}
		}

	}
	else
	{
		cout << "파일을 찾을 수 없습니다" << endl;
	}



}


// 보통예금계좌 개설
void AccountHandler::MakeNormalAccount(void)
{
	system("cls");

	int id; //계좌번호
	char name[NAME_LEN]; //고객명
	int balance; //잔액
	int interestRate = 0; //이자율

	cout << endl;
	cout<<"  "<< "[보통예금계좌 개설]" << endl;
	cout<<"  "<< "계좌번호 : "; cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (id == accArr[i]->GetID())
		{
			cout<<"  "<< "이미 존재하는 계좌입니다" << endl;
			getchar();
			getchar();
			return;
		}
	}
	cout<<"  "<< "고객명 : "; cin >> name;
	cout<<"  "<< "잔액 : "; cin >> balance;
	cout<<"  "<< "이자율 :"; cin >> interestRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(NORMAL, id, balance, name, interestRate);


	getchar();


}

// 신용신뢰계좌 개설
void AccountHandler::MakeCreditAccount(void)
{
	system("cls");

	int id; //계좌번호
	char name[NAME_LEN]; //고객명
	int balance; //잔액
	int interestRate = 0; //이자율
	int creditclass; //신용등급

	cout << endl;
	cout<<"  "<< "[신용신뢰계좌 개설]" << endl;
	cout<<"  "<< "계좌번호 : "; cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (id == accArr[i]->GetID())
		{
			cout << "이미 존재하는 계좌입니다" << endl;
			getchar();
			getchar();
			return;
		}
	}
	cout<<"  "<< "고객명 : "; cin >> name;
	cout<<"  "<< "잔액 : "; cin >> balance;
	cout<<"  "<< "이자율 :"; cin >> interestRate;
	cout<<"  "<< "신용등급(A등급:7 /B등급:4/ C등급:2) : "; cin >> creditclass;
	cout << endl;

	accArr[accNum++] = new HighCreditAccount(CREDIT, id, balance, name, interestRate, creditclass);

	getchar();


}

// 입금
void AccountHandler::DepositMoney(void)
{
	system("cls");

	int money; //입금액
	int id; //계좌번호

	cout << endl;
	cout<<"  "<< "[입 금]" << endl;
	cout<<"  "<< "계좌번호 : "; cin >> id;
	cout<<"  "<< "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			try
			{
				accArr[i]->Deposit(money);
				cout << endl;
				cout<<"  "<< "->입금완료되었습니다." << endl;
				getchar();

			}

			catch (DepositException &expn)
			{
				expn.ShowExceptionReason();
				getchar();
			}
			getchar();
			return;
		}

	}

	cout << "잘못된 계좌번호입니다." << endl << endl;

	getchar();
	getchar();

}

// 출금
void AccountHandler::WithdrawMoney(void)
{
	system("cls");

	int money; //출금액
	int id; //계좌번호

	cout << endl;
	cout<<"  "<< "[출 금]" << endl;
	cout<<"  "<< "계좌번호 : "; cin >> id;
	cout<<"  "<< "출금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{

		if (accArr[i]->GetID() == id)
		{
			try
			{
				if (accArr[i]->Getbalance() < money)
				{
					cout << "잔액이 부족합니다." << endl << endl;
					getchar();
					getchar();
					return;

				}
				accArr[i]->WithdrawMoney(money);
				cout << endl;
				cout<<"  "<< "->출금이 완료되었습니다." << endl << endl;
				getchar();
				getchar();
				return;
			}

			catch (WithdrawException &expn)
			{
				expn.ShowExceptionReason();
				getchar();
			}

			getchar();
			getchar();
			return;
		}
	}

	cout << "잘못된 계좌번호입니다." << endl << endl;

	getchar();
	getchar();

}

// 전체고객 잔액조회
void AccountHandler::ShowAllAccInfo(void)
{
	system("cls");

	cout << endl;
	cout<<"  "<< "[전체고객 잔액조회]" << endl;

	for (int i = 0; i < accNum; i++)
	{
		cout<<"  "<< "--------------------" << endl;
		cout<<"  "<< "계좌번호 : " << accArr[i]->GetID() << endl;
		cout<<"  "<< "고객명 : " << accArr[i]->Getname() << endl;
		cout<<"  "<< "잔액 : " << accArr[i]->Getbalance() << endl;
		cout<<"  "<< "--------------------" << endl;
	}
	getchar();
	getchar();

}

bool AccountHandler::AccountCnt(void)
{
	try {
		if (accNum == NumOfUser)
		{
			AccountException expn(accNum);
			throw expn;
		}

	}
	catch (AccountException& expn)
	{
		expn.ShowExceptionReason();
		return false;
	}
	return true;
}


AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		if (i == 0)
		{
			ofstream fout("AccountList.txt");
			fout << accArr[i]->Getnum() << ' ' << accArr[i]->GetID() << ' ' << accArr[i]->Getbalance() << ' ' << accArr[i]->Getname() << ' ';

			fout.close();
		}
		else {
			ofstream fout("AccountList.txt", ios::app);
			fout << endl << accArr[i]->Getnum() << ' ' << accArr[i]->GetID() << ' ' << accArr[i]->Getbalance() << ' ' << accArr[i]->Getname() << ' ';

			fout.close();
		}
		delete accArr[i];
	}
}