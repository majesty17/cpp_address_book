
#include "Person.cpp"

using namespace std;

struct ListNode {
   Person p;
   struct ListNode *next;
   int code; //�ڵ���
   ListNode(Person x) : p(x), next(NULL) {}  // �ڵ�Ĺ��캯����һ���ڵ��Ӧһ����ϵ��
};
