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
    cout << "������������:\n";
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
        cout << "������������:\n";
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
    if (l1== nullptr && l2== nullptr && bit == 0){//�ݹ�߽� 
        return nullptr;
    }
    //��ǰ������Ե����
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
    Linklist node = new Linknode;//�����µĽ����װ��������ĺ�
    node->num = num%10;
    node->next = addtwo(l1,l2,num/10);//�е��������ã�1�������µ�����2����ʼ������һλ
    return node;//�ݹ������Ҫ����node��
}
int main()
{
    cout << "����l1:";
    Linklist l1 = creat();
    cout << "����l2:";
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