
#include "Person.cpp"

using namespace std;

struct ListNode {
   Person p;
   struct ListNode *next;
   int code; //节点编号
   ListNode(Person x) : p(x), next(NULL) {}  // 节点的构造函数，一个节点对应一个联系人
};
