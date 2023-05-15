#include<iostream>
#include "AddressBook.cpp"

using namespace std;
//菜单界面
void showMenu()
{
	cout << "\n*******   请选择功能   *****" << endl;
	cout << "*****  1. 通讯录列表   *****" << endl;
	cout << "*****  2. 联系人详情   *****" << endl;
	cout << "*****  3. 添加联系人   *****" << endl;
	cout << "*****  4. 删除联系人   *****" << endl;
	cout << "*****  5. 修改联系人   *****" << endl;
	cout << "*****  0. 退出通讯录   *****" << endl;
	cout << "***************************" << endl;
 
}

// 修改联系人明细菜单
void showMenu_modify()
{
    cout << "** 请选择要修改哪项 **" << endl;
    cout << "*****  1. 姓名   *****" << endl;
	cout << "*****  2. 性别   *****" << endl;
	cout << "*****  3. 年龄   *****" << endl;
	cout << "*****  4. 电话   *****" << endl;
	cout << "*****  5. 地址   *****" << endl;
    cout << "*****  0. 退出编辑 ***" << endl;
}




int main()
{
    //初始化通讯录，
    AddressBook addr_book = AddressBook();
    //从文件导入
    addr_book.loadContacts();


    //进入循环
    while (true)
	{
		int select = 0;     //创建用户选择输入的变量
        int selected = 0;   //选中修改、详情展示、删除 等等操作的编号
        int item_idx;       //修改联系人的项目编号
        string item_new;    //修改联系人的项目新值
        string temp;
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://列出通讯录
            cout << "*** 列出通讯录 ***" << endl;
            addr_book.listContacts();
            cout << "*** 列出通讯录 ***" << endl;

			break;
		case 2://联系人详情
            cout << "*** 联系人详情 ***" << endl;
            cout << "请输入联系人编号:" << endl;
            cin >> selected;
            addr_book.showContractDetails(selected);
            cout << "*** 联系人详情 ***" << endl;
			break;
		case 3://添加联系人
            cout << "*** 添加联系人 ***" << endl;
            cout << "请输入姓名,性别,年龄,电话,住址(逗号隔开):" << endl;
            cin >> temp ;
            addr_book.addContact(Person(temp));
            cout << "*** 添加联系人 ***" << endl;

			break;
		case 4://删除联系人
            cout << "*** 删除联系人 ***" << endl;
            cout << "请输入要删除的联系人编号:" << endl;
            cin >> selected;
            addr_book.removeContact(selected);
            cout << "*** 删除联系人 ***" << endl;
			break;
		case 5://修改联系人
            cout << "*** 修改联系人 ***" << endl;
            cout << "请输入联系人编号:" << endl;
            cin >> selected;
            cout << "请选择要修改的项目:" << endl;
            showMenu_modify();
            cin >> item_idx;
            cout << "请输入新的值:" << endl;
            cin >> item_new;
            addr_book.modifyContact(selected, item_idx, item_new);
            cout << "*** 修改联系人 ***" << endl;
			break;
		case 0://退出通讯录
            addr_book.saveContacts();
			cout << "欢迎下次使用!" << endl;
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