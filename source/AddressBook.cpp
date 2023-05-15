#include <iostream>
#include <string>
#include <fstream>


#include "ListNode.cpp"

using namespace std;

class AddressBook {
private:
    ListNode* addr_book = NULL;
public:
    AddressBook(){
    }

    // ����һ���µ���ϵ�ˣ����ص�ǰ�ܵ���ϵ������
    int addContact(Person p) {
        //���뵽����β��
        if (addr_book == NULL){
            this->addr_book = new ListNode(p);
            addr_book->code = 1;
            return 1;
        }
        else{ //�ӵڶ�����ʼ�������ǰһ����һ,��֤���Ψһ
            int i = 2;
            ListNode* ptr = addr_book;
            while (ptr->next != NULL){
                ptr = ptr->next;
                i++;
            }
            ptr->next = new ListNode(p);
            ptr->next->code = ptr->code + 1;
            return i;
        }

    }

    // ɾ����ϵ��
    void removeContact(int n)
    {
        ListNode* ptr = addr_book;
        
        // �յ�,ʲô��û
        if(ptr == NULL)
        {
            cout << "����ϵ�˿�ɾ!" << endl;
            return;
        }
        // ���ɾ���ǵ�һ��
        else if(ptr->code == n)
        {
            addr_book = ptr->next;
            delete ptr;
            return;
        }
        else //����ǵ�һ��֮���
        {
            ListNode* ptr_pre = ptr; //ǰ�ڵ�
            ptr = ptr->next;

            while (ptr != NULL)
            {
                if(ptr->code == n) 
                {
                    ptr_pre->next = ptr->next; //ɾ��ptrָ���node��
                    delete ptr;
                    return;
                }
                //cout << ptr->code << ":" << ptr->p.getName() << endl;
                ptr_pre = ptr;
                ptr = ptr->next;
                
            }
            cerr << "δ�ҵ����Ϊ<" << n << ">����ϵ�ˣ�" << endl;
            return;
        }
        return;
    }

    // �޸���ϵ��


    void modifyContact(int n , int item, string value)
    {
        ListNode* ptr = addr_book;
        while (ptr != NULL)
        {
            if(ptr->code == n)
            {
                switch (item)
                {
                case 1:
                    ptr->p.setName(value);
                    break;
                case 2:
                    ptr->p.setSex(value);
                    break;
                case 3:
                    ptr->p.setAge(value);
                    break;
                case 4:
                    ptr->p.setPhone(value);
                    break;
                case 5:
                    ptr->p.setAddr(value);
                    break;
                default:
                    cout << "��Ŀ��Ų���ȷ(1~5)" << endl;
                    break;
                }

                return;
            }
            //cout << ptr->code << ":" << ptr->p.getName() << endl;
            ptr = ptr->next;
        }
        cerr << "δ�ҵ����Ϊ<" << n << ">����ϵ�ˣ�" << endl;
        return;
    }




    // �г���ǰͨѶ¼
    void listContacts() const {
        ListNode* ptr = addr_book;
        cout << "���:\t����" << endl; 
        while (ptr != NULL)
        {
            cout << ptr->code << ":\t" << ptr->p.getName() << endl;
            ptr = ptr->next;
        }
    }

    // ����id��ʾ����ϵ������
    void showContractDetails(int n)
    {
        ListNode* ptr = addr_book;
        while (ptr != NULL)
        {
            if(ptr->code == n)
            {
                cout << "���:  " << ptr->code << endl;
                cout << "����:  " << ptr->p.getName() << endl;
                cout << "�Ա�:  " << ptr->p.getSex() << endl;
                cout << "����:  " << ptr->p.getAge() << endl;
                cout << "�绰:  " << ptr->p.getPhone() << endl;
                cout << "��ַ:  " << ptr->p.getAddr() << endl;
                return;
            }
            //cout << ptr->code << ":" << ptr->p.getName() << endl;
            ptr = ptr->next;
        }
        cerr << "δ�ҵ����Ϊ<" << n << ">����ϵ�ˣ�" << endl;
        return;
    }

    // ���ļ��ж�ȡ
    void loadContacts()
    {
        ifstream readFile;
        readFile.open("data.txt");
        if (readFile){
            cout << "�ļ��򿪳ɹ���" << endl;
            string temp;
            int i;
            while (getline(readFile, temp)){
                //cout << temp << endl;
                i = this->addContact(Person(temp));
            }
            cout << i << "����ϵ���ѵ���!" << endl;
        }
        else{
            cerr << "�ļ���ʧ��!" << endl;
            return;
        }
        readFile.close();
    }

    // ���浽�ļ�
    void saveContacts()
    {
        ofstream outFile;	//����ofstream����outFile
        outFile.open("data.txt");	//���ļ�
        
        ListNode* ptr = addr_book;
        while (ptr != NULL)
        {
            Person p = ptr->p;

            outFile << p.getName()<<"," <<p.getSex() << "," << p.getAge() << "," << p.getPhone() << "," << p.getAddr() << endl;
            ptr = ptr->next;
        }

        //outFile << "����,��,1999,13300000000,�����ж�����" << endl; //д����� 
        outFile.close();	//�ر��ļ�
    }
};


