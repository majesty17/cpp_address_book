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

    // 插入一个新的联系人，返回当前总的联系人数量
    int addContact(Person p) {
        //插入到链表尾部
        if (addr_book == NULL){
            this->addr_book = new ListNode(p);
            addr_book->code = 1;
            return 1;
        }
        else{ //从第二个开始，编号是前一个加一,保证编号唯一
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

    // 删除联系人
    void removeContact(int n)
    {
        ListNode* ptr = addr_book;
        
        // 空的,什么都没
        if(ptr == NULL)
        {
            cout << "无联系人可删!" << endl;
            return;
        }
        // 如果删的是第一个
        else if(ptr->code == n)
        {
            addr_book = ptr->next;
            delete ptr;
            return;
        }
        else //如果是第一个之后的
        {
            ListNode* ptr_pre = ptr; //前节点
            ptr = ptr->next;

            while (ptr != NULL)
            {
                if(ptr->code == n) 
                {
                    ptr_pre->next = ptr->next; //删除ptr指向的node；
                    delete ptr;
                    return;
                }
                //cout << ptr->code << ":" << ptr->p.getName() << endl;
                ptr_pre = ptr;
                ptr = ptr->next;
                
            }
            cerr << "未找到编号为<" << n << ">的联系人！" << endl;
            return;
        }
        return;
    }

    // 修改联系人


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
                    cout << "项目编号不正确(1~5)" << endl;
                    break;
                }

                return;
            }
            //cout << ptr->code << ":" << ptr->p.getName() << endl;
            ptr = ptr->next;
        }
        cerr << "未找到编号为<" << n << ">的联系人！" << endl;
        return;
    }




    // 列出当前通讯录
    void listContacts() const {
        ListNode* ptr = addr_book;
        cout << "编号:\t姓名" << endl; 
        while (ptr != NULL)
        {
            cout << ptr->code << ":\t" << ptr->p.getName() << endl;
            ptr = ptr->next;
        }
    }

    // 根据id显示出联系人详情
    void showContractDetails(int n)
    {
        ListNode* ptr = addr_book;
        while (ptr != NULL)
        {
            if(ptr->code == n)
            {
                cout << "编号:  " << ptr->code << endl;
                cout << "姓名:  " << ptr->p.getName() << endl;
                cout << "性别:  " << ptr->p.getSex() << endl;
                cout << "年龄:  " << ptr->p.getAge() << endl;
                cout << "电话:  " << ptr->p.getPhone() << endl;
                cout << "地址:  " << ptr->p.getAddr() << endl;
                return;
            }
            //cout << ptr->code << ":" << ptr->p.getName() << endl;
            ptr = ptr->next;
        }
        cerr << "未找到编号为<" << n << ">的联系人！" << endl;
        return;
    }

    // 从文件中读取
    void loadContacts()
    {
        ifstream readFile;
        readFile.open("data.txt");
        if (readFile){
            cout << "文件打开成功！" << endl;
            string temp;
            int i;
            while (getline(readFile, temp)){
                //cout << temp << endl;
                i = this->addContact(Person(temp));
            }
            cout << i << "个联系人已导入!" << endl;
        }
        else{
            cerr << "文件打开失败!" << endl;
            return;
        }
        readFile.close();
    }

    // 保存到文件
    void saveContacts()
    {
        ofstream outFile;	//定义ofstream对象outFile
        outFile.open("data.txt");	//打开文件
        
        ListNode* ptr = addr_book;
        while (ptr != NULL)
        {
            Person p = ptr->p;

            outFile << p.getName()<<"," <<p.getSex() << "," << p.getAge() << "," << p.getPhone() << "," << p.getAddr() << endl;
            ptr = ptr->next;
        }

        //outFile << "张三,男,1999,13300000000,北京市东城区" << endl; //写入操作 
        outFile.close();	//关闭文件
    }
};


