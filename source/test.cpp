#include<iostream>
#include "AddressBook.cpp"

using namespace std;
//�˵�����
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1,�����ϵ�� *****" << endl;
	cout << "***** 2,��ʾ��ϵ�� *****" << endl;
	cout << "***** 3,ɾ����ϵ�� *****" << endl;
	cout << "***** 4,������ϵ�� *****" << endl;
	cout << "***** 5,�޸���ϵ�� *****" << endl;
	cout << "***** 6,�����ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
 
}
int main()
{
    AddressBook addr_book = AddressBook();
    //addr_book.saveContacts();
    addr_book.loadContacts();

    while (true)
	{
		int select = 0;//�����û�ѡ������ı���
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			break;
		case 2://��ʾ��ϵ��
			break;
		case 3://ɾ����ϵ��
			break;
		case 4://������ϵ��
			break;
		case 5://�޸���ϵ��
			break;
		case 6://�����ϵ��
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}