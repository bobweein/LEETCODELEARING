#include <iostream>
#include "lei.h"
using namespace std;

LINK::LINK()
{
    Head.num = 0;
    Head.next = NULL;
    lng = 0;
}

bool LINK::isempty()
{
    return Head.next == NULL;
}

bool LINK::islast(Linknode& n)const
{
    return n.next == NULL;
}

void LINK::creat()
{
    Linklist p, q;
    int n = 0;
    p = q = new Linknode;
    cout << "请输入结点数据:\n";
    (cin >> q->num).get();
    q->next = NULL;
    while (q->num)
    {
        lng++;
        n++;
        if (n == 1) Head.next = q;
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
}

bool LINK::insert(datatype a, position pt)
{
    if (pt > lng + 1)
    {
        cout << "这个位置超出了链表现在的最长长度!" << endl;
        return false;
    }
    Linklist q = NULL, p = NULL;
    q = new Linknode;
    int i = 0;
    p = &Head;
    while (i < pt - 1 && p->next)
    {
        p = p->next;
        i++;
    }
    q->num = a;
    Linklist temp = NULL;
    if (i == 0 || p->next == NULL)
    {
        p->next = q;
        q->next = NULL;
        lng++;
        return true;
    }
    else
    {
        temp = p->next;
        q->next = temp;
        p->next = q;
        lng++;
        return true;
    }
}
void LINK::showlink()
{
    Linklist p = Head.next;
    while (p)
    {
        cout << p->num << "\t";
        p = p->next;
    }
    cout << endl;
}
