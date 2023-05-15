#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Person {
public:
    //简易构造函数，姓名和性别
    Person(string n, string s) : name(n), sex(s) {}
    //完整构造函数
    Person(string n,string s,string ag,string p,string add) : name(n), sex(s), age(ag), phone(p), address(add){}
    //一整行的构造函数，逗号隔开
    Person(string n){
        istringstream iss(n);	// 输入流
        string token;			// 接收缓冲区

        getline(iss, token, ',');
        name = token;
        getline(iss, token, ',');
        sex = token;
        getline(iss, token, ',');
        age = token;
        getline(iss, token, ',');
        phone = token;
        getline(iss, token, ',');
        address = token;
    }

    string getName() const { return name; }
    string getSex() const {return sex;}
    string getAge() const { return age; }
    string getPhone() const { return phone; }
    string getAddr() const { return address; }

    void setName(string n) { name = n; }
    void setSex(string n) { sex = n; }
    void setAge(string n) { age = n; } 
    void setPhone(string p) { phone = p; }
    void setAddr(string n) { address = n; }
private:
    string name;
    string sex;
    string age;
    string phone;
    string address;
};