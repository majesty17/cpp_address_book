#include<iostream>
#include "AddressBook.cpp"

using namespace std;
//菜单界面
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1,添加联系人 *****" << endl;
	cout << "***** 2,显示联系人 *****" << endl;
	cout << "***** 3,删除联系人 *****" << endl;
	cout << "***** 4,查找联系人 *****" << endl;
	cout << "***** 5,修改联系人 *****" << endl;
	cout << "***** 6,清空联系人 *****" << endl;
	cout << "***** 0，退出通讯录 *****" << endl;
	cout << "************************" << endl;
 
}
int main()
{
    AddressBook addr_book = AddressBook();
    //addr_book.saveContacts();
    addr_book.loadContacts();

    while (true)
	{
		int select = 0;//创建用户选择输入的变量
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			break;
		case 2://显示联系人
			break;
		case 3://删除联系人
			break;
		case 4://查找联系人
			break;
		case 5://修改联系人
			break;
		case 6://清空联系人
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
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