#include "manage.h"
#include <iostream>
#include <iomanip>
using namespace std;

void showMenu() {

    const int WIDTH = 9;

    cout << "\t"<<string(WIDTH + 3, '*') << endl;
    cout << "\t" << "* " << setfill(' ') << left << setw(WIDTH) << "1.add" << '*' << endl;
    cout << "\t" << "* " << setw(WIDTH) << "2.show" << '*' << endl;
    cout << "\t" << "* " << setw(WIDTH) << "3.delete" << '*' << endl;
    cout << "\t" << "* " << setw(WIDTH) << "4.find" << '*' << endl;
    cout << "\t" << "* " << setw(WIDTH) << "5.modify" << '*' << endl;
    cout << "\t" << "* " << setw(WIDTH) << "6.clear" << '*' << endl;
    cout << "\t" << "* " << setw(WIDTH) << "0.exit" << '*' << endl;
    cout << "\t" << string(WIDTH + 3, '*') << endl;

    cout << "\t" << "--请输入操作--" << endl;
}

//1.add
void addPerson(Addressbooks* abs){
    if (abs->m_Size == MAX) {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else {
        cout << "请输入姓名" << endl;
        cin >> abs->personArray[abs->m_Size].m_Name;
        cout << "请输入性别：* 1---男，2---女 *" << endl;
        int sex;
        cin >> sex;
        while (sex != 1 && sex != 2) {
            cout << "输入有误，请再次输入" << endl;
            cin >> sex;
        }
        abs->personArray[abs->m_Size].m_Sex = sex;
        cout << "请输入年龄:" << endl;
        cin >> abs->personArray[abs->m_Size].m_Age;
        cout << "请输入电话号码:" << endl;
        cin >> abs->personArray[abs->m_Size].m_Phone;
        cout << "请输入家庭地址:" << endl;
        cin >> abs->personArray[abs->m_Size].m_Addr;
        abs->m_Size++;
        cout << "--添加成功!--" << endl;

    }
}

//2.show
void showPerson(Addressbooks* abs) {
    //判断通讯录中人数
    if (abs->m_Size == 0) {
        cout << "通讯录内容为空" << endl;
    }
    else {
        for (int i = 0; i < abs->m_Size; i++) {
            cout << "姓名:" << abs->personArray[i].m_Name << "\t";
            cout << "性别:";
            if (abs->personArray[i].m_Sex == 1) {
                cout << "男";
            }
            else if (abs->personArray[i].m_Sex == 2) {
                cout << "女";
            }
            cout << "\t";
            cout << "年龄:" << abs->personArray[i].m_Age << "\t";
            cout << "电话号码:" << abs->personArray[i].m_Phone << "\t";
            cout << "家庭住址:" << abs->personArray[i].m_Addr << endl;
        }
    }
}

//3.delete
int isExist(Addressbooks* abs, string name) {
    int index = -1;
    for (int i = 0; i < abs->m_Size; i++) {
        if (abs->personArray[i].m_Name == name) {
            index = i;
            break;
        }
    }
    return index;
}

void deletePerson(Addressbooks* abs) {
    cout << "请输入需要删除的联系人姓名" << endl;
    string s;
    cin >> s;
    int index = isExist(abs, s);
    if (index == -1) {
        cout << "--该联系人不存在！--" << endl;
    }
    else {
        for (int i = index; i < abs->m_Size - 1; i++) {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "--删除成功！--" << endl;
    }
}

//4.find
void findPerson(Addressbooks* abs) {
    cout << "请输入您要查找的联系人姓名"<<endl;
    string name;
    cin >> name;
    int index = isExist(abs,name);
    if (index == -1) {
        cout << "--查无此人--" << endl;
    }
    else {
        cout << "姓名:" << abs->personArray[index].m_Name << "\t";
        cout << "性别:";
        if (abs->personArray[index].m_Sex == 1) {
            cout << "男";
        }
        else if (abs->personArray[index].m_Sex == 2) {
            cout << "女";
        }
        cout << "\t";
        cout << "年龄:" << abs->personArray[index].m_Age << "\t";
        cout << "电话号码:" << abs->personArray[index].m_Phone << "\t";
        cout << "家庭住址:" << abs->personArray[index].m_Addr << endl;
    }
}

//5.motify
void motifyPerson(Addressbooks* abs) {
    cout << "请输入需要修改的联系人姓名" << endl;
    string s;
    cin >> s;
    int index = isExist(abs, s);
    if (index == -1) {
        cout << "查无此人" << endl;
    }
    else {
        cout << "请输入修改后的姓名" << endl;
        cin >> abs->personArray[index].m_Name;
        cout << "请输入性别：* 1---男，2---女 *" << endl;
        int sex;
        cin >> sex;
        while (sex != 1 && sex != 2) {
            cout << "输入有误，请再次输入" << endl;
            cin >> sex;
        }
        abs->personArray[index].m_Sex = sex;
        cout << "请输入年龄:" << endl;
        cin >> abs->personArray[index].m_Age;
        cout << "请输入电话号码:" << endl;
        cin >> abs->personArray[index].m_Phone;
        cout << "请输入家庭地址:" << endl;
        cin >> abs->personArray[index].m_Addr;
        cout << "--修改成功!--" << endl;
    }
}

//6.clear
void clearPerson(Addressbooks* abs) {
    cout << "确认要清空联系人吗？(1-是，2-取消)" << endl;
    int num = 0;
        cin >> num;
        if (num == 1) {
            abs->m_Size = 0;
            cout << "--通讯录已清空--" << endl;
        }
        else {
            cout << "--操作已取消--" << endl;
        }
    
}
