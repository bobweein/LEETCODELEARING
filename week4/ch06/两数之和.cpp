#include <iostream>
using std::cout;
using std::cin;
typedef int data;
typedef struct Node
{
    data num;
    Node* next;
}Linknode,*Linklist;
Linklist addtwo(Linknode l1, Linknode l2, int bit);
Linklist creat();
Linklist creat()
{
    Linklist Head=new Linknode;
    Linklist p, q;
    int n = 0;
    p = q = new Linknode;
    cout << "请输入结点数据:\n";
    (cin >> q->num).get();
    q->next = NULL;
    while (q->num)
    {
        n++;
        if (n == 1) Head= q;
        else
        {
            p->next = q;
            p = q;
        }
        cout << "请输入结点数据:\n";
        q = new Linknode;
        (cin >> q->num).get();
        q->next = NULL;
    }
    p->next = NULL;
    return Head;
}
Linknode* addtwo(Linklist l1, Linklist l2, int bit)
{
    int num = bit;
    if (l1== nullptr && l2== nullptr && bit == 0){//递归边界 
        return nullptr;
    }
    //当前可能面对的情况
    if (l1 != nullptr)
    {
        num += l1->num;
        l1 = l1->next;
    }
    if (l2 != nullptr)
    {
        num += l2->num;
        l2 = l2->next;
    }
    Linklist node = new Linknode;//创建新的结点来装两个链表的和
    node->num = num%10;
    node->next = addtwo(l1,l2,num/10);//承担两个作用，1、链接新的链表。2、开始计算下一位
    return node;//递归结束后，要返回node。
}
int main()
{
    cout << "链表l1:";
    Linklist l1 = creat();
    cout << "链表l2:";
    Linklist l2 = creat();
    Linklist Head = addtwo(l1, l2,0);
    Linklist P = Head;
    while (P)
    {
        cout << P->num<<"  ";
        P = P->next;
    }
    return 0;
}