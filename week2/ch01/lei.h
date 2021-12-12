
#ifndef _LEI_H
#define _LEI_H
typedef int datatype;
typedef int position;
typedef struct node
{
    datatype num;
    node* next;
}Linknode, * Linklist;
class LINK
{
private:
    Linknode Head;
    int  lng;
public:
    LINK();
    void creat();
    bool insert(datatype a, position p);
    bool islast(Linknode& n)const;
    bool isempty();
    void showlink();
};
#endif
