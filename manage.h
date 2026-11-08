#ifndef MANAGE_H
#define MANAGE_H

#include<string>
using namespace std;

#define MAX 1000
//设计联系人结构体

struct Person
{
    string m_Name;
    int m_Sex=0;
    int m_Age=0;
    string m_Phone;
    string m_Addr;
};

//设计通讯录结构体
struct Addressbooks {
    //通讯录中保存的联系人数组
    struct Person personArray[MAX];

    //通讯录中当前记录的联系人个数
    int m_Size = 0;
};

void showMenu();
void showPerson(Addressbooks* abs);
void addPerson(Addressbooks* abs);
int isExist(Addressbooks* abs, string name);
void deletePerson(Addressbooks* abs);
void findPerson(Addressbooks* abs);
void motifyPerson(Addressbooks* abs);
void clearPerson(Addressbooks* abs);

#endif