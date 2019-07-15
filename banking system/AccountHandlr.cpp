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
	cout<< "  " << "1. ���°���" << endl;
	cout<< "  " << "2. ��    ��" << endl;
	cout<< "  " << "3. ��    ��" << endl;
	cout<< "  " << "4. ��ü�� �ܾ���ȸ" << endl;
	cout<< "  " << "5. ��    ��" << endl;
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
		cout << "������ ã�� �� �����ϴ�" << endl;
	}



}


// ���뿹�ݰ��� ����
void AccountHandler::MakeNormalAccount(void)
{
	system("cls");

	int id; //���¹�ȣ
	char name[NAME_LEN]; //����
	int balance; //�ܾ�
	int interestRate = 0; //������

	cout << endl;
	cout<<"  "<< "[���뿹�ݰ��� ����]" << endl;
	cout<<"  "<< "���¹�ȣ : "; cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (id == accArr[i]->GetID())
		{
			cout<<"  "<< "�̹� �����ϴ� �����Դϴ�" << endl;
			getchar();
			getchar();
			return;
		}
	}
	cout<<"  "<< "���� : "; cin >> name;
	cout<<"  "<< "�ܾ� : "; cin >> balance;
	cout<<"  "<< "������ :"; cin >> interestRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(NORMAL, id, balance, name, interestRate);


	getchar();


}

// �ſ�ŷڰ��� ����
void AccountHandler::MakeCreditAccount(void)
{
	system("cls");

	int id; //���¹�ȣ
	char name[NAME_LEN]; //����
	int balance; //�ܾ�
	int interestRate = 0; //������
	int creditclass; //�ſ���

	cout << endl;
	cout<<"  "<< "[�ſ�ŷڰ��� ����]" << endl;
	cout<<"  "<< "���¹�ȣ : "; cin >> id;
	for (int i = 0; i < accNum; i++)
	{
		if (id == accArr[i]->GetID())
		{
			cout << "�̹� �����ϴ� �����Դϴ�" << endl;
			getchar();
			getchar();
			return;
		}
	}
	cout<<"  "<< "���� : "; cin >> name;
	cout<<"  "<< "�ܾ� : "; cin >> balance;
	cout<<"  "<< "������ :"; cin >> interestRate;
	cout<<"  "<< "�ſ���(A���:7 /B���:4/ C���:2) : "; cin >> creditclass;
	cout << endl;

	accArr[accNum++] = new HighCreditAccount(CREDIT, id, balance, name, interestRate, creditclass);

	getchar();


}

// �Ա�
void AccountHandler::DepositMoney(void)
{
	system("cls");

	int money; //�Աݾ�
	int id; //���¹�ȣ

	cout << endl;
	cout<<"  "<< "[�� ��]" << endl;
	cout<<"  "<< "���¹�ȣ : "; cin >> id;
	cout<<"  "<< "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			try
			{
				accArr[i]->Deposit(money);
				cout << endl;
				cout<<"  "<< "->�ԱݿϷ�Ǿ����ϴ�." << endl;
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

	cout << "�߸��� ���¹�ȣ�Դϴ�." << endl << endl;

	getchar();
	getchar();

}

// ���
void AccountHandler::WithdrawMoney(void)
{
	system("cls");

	int money; //��ݾ�
	int id; //���¹�ȣ

	cout << endl;
	cout<<"  "<< "[�� ��]" << endl;
	cout<<"  "<< "���¹�ȣ : "; cin >> id;
	cout<<"  "<< "��ݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{

		if (accArr[i]->GetID() == id)
		{
			try
			{
				if (accArr[i]->Getbalance() < money)
				{
					cout << "�ܾ��� �����մϴ�." << endl << endl;
					getchar();
					getchar();
					return;

				}
				accArr[i]->WithdrawMoney(money);
				cout << endl;
				cout<<"  "<< "->����� �Ϸ�Ǿ����ϴ�." << endl << endl;
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

	cout << "�߸��� ���¹�ȣ�Դϴ�." << endl << endl;

	getchar();
	getchar();

}

// ��ü�� �ܾ���ȸ
void AccountHandler::ShowAllAccInfo(void)
{
	system("cls");

	cout << endl;
	cout<<"  "<< "[��ü�� �ܾ���ȸ]" << endl;

	for (int i = 0; i < accNum; i++)
	{
		cout<<"  "<< "--------------------" << endl;
		cout<<"  "<< "���¹�ȣ : " << accArr[i]->GetID() << endl;
		cout<<"  "<< "���� : " << accArr[i]->Getname() << endl;
		cout<<"  "<< "�ܾ� : " << accArr[i]->Getbalance() << endl;
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