#include<iostream>
#include"lei.h"
int main()
{
    LINK list;
    list.creat();
    list.showlink();
    list.insert(999, 3);
    list.showlink();
    list.insert(9999, 5);
    list.showlink();
    return 0;

}
