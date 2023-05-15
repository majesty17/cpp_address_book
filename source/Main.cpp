#include<iostream>
#include "AddressBook.cpp"

using namespace std;
//�˵�����
void showMenu()
{
	cout << "\n*******   ��ѡ����   *****" << endl;
	cout << "*****  1. ͨѶ¼�б�   *****" << endl;
	cout << "*****  2. ��ϵ������   *****" << endl;
	cout << "*****  3. �����ϵ��   *****" << endl;
	cout << "*****  4. ɾ����ϵ��   *****" << endl;
	cout << "*****  5. �޸���ϵ��   *****" << endl;
	cout << "*****  0. �˳�ͨѶ¼   *****" << endl;
	cout << "***************************" << endl;
 
}

// �޸���ϵ����ϸ�˵�
void showMenu_modify()
{
    cout << "** ��ѡ��Ҫ�޸����� **" << endl;
    cout << "*****  1. ����   *****" << endl;
	cout << "*****  2. �Ա�   *****" << endl;
	cout << "*****  3. ����   *****" << endl;
	cout << "*****  4. �绰   *****" << endl;
	cout << "*****  5. ��ַ   *****" << endl;
    cout << "*****  0. �˳��༭ ***" << endl;
}




int main()
{
    //��ʼ��ͨѶ¼��
    AddressBook addr_book = AddressBook();
    //���ļ�����
    addr_book.loadContacts();


    //����ѭ��
    while (true)
	{
		int select = 0;     //�����û�ѡ������ı���
        int selected = 0;   //ѡ���޸ġ�����չʾ��ɾ�� �ȵȲ����ı��
        int item_idx;       //�޸���ϵ�˵���Ŀ���
        string item_new;    //�޸���ϵ�˵���Ŀ��ֵ
        string temp;
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://�г�ͨѶ¼
            cout << "*** �г�ͨѶ¼ ***" << endl;
            addr_book.listContacts();
            cout << "*** �г�ͨѶ¼ ***" << endl;

			break;
		case 2://��ϵ������
            cout << "*** ��ϵ������ ***" << endl;
            cout << "��������ϵ�˱��:" << endl;
            cin >> selected;
            addr_book.showContractDetails(selected);
            cout << "*** ��ϵ������ ***" << endl;
			break;
		case 3://�����ϵ��
            cout << "*** �����ϵ�� ***" << endl;
            cout << "����������,�Ա�,����,�绰,סַ(���Ÿ���):" << endl;
            cin >> temp ;
            addr_book.addContact(Person(temp));
            cout << "*** �����ϵ�� ***" << endl;

			break;
		case 4://ɾ����ϵ��
            cout << "*** ɾ����ϵ�� ***" << endl;
            cout << "������Ҫɾ������ϵ�˱��:" << endl;
            cin >> selected;
            addr_book.removeContact(selected);
            cout << "*** ɾ����ϵ�� ***" << endl;
			break;
		case 5://�޸���ϵ��
            cout << "*** �޸���ϵ�� ***" << endl;
            cout << "��������ϵ�˱��:" << endl;
            cin >> selected;
            cout << "��ѡ��Ҫ�޸ĵ���Ŀ:" << endl;
            showMenu_modify();
            cin >> item_idx;
            cout << "�������µ�ֵ:" << endl;
            cin >> item_new;
            addr_book.modifyContact(selected, item_idx, item_new);
            cout << "*** �޸���ϵ�� ***" << endl;
			break;
		case 0://�˳�ͨѶ¼
            addr_book.saveContacts();
			cout << "��ӭ�´�ʹ��!" << endl;
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