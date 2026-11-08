//封装函数显示该界面 如void showMenu()
//在main函数中调用封装好的函数
#include"manage.h"
#include<iostream>
#include<iomanip>
using namespace std;



int main() {

    //创建通讯录结构体变量
    Addressbooks abs;


    //创建用户选择输入的变量
    int select = 0;

    //菜单调用
    showMenu();
    cin >> select;
    while (true) {
        switch (select) {
        case 1:
            addPerson(&abs);//传地址，改实参
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
            deletePerson(&abs);
            break;
        case 4:
            findPerson(&abs);
            break;
        case 5:
            motifyPerson(&abs);
            break;
        case 6:
            clearPerson(&abs);
            break;
        case 0:
            cout << "--欢迎下次使用--" << endl;
            system("pause>nul");
            return 0;
            break;
        default:
            break;
        }
        cout << "\n--请按任意键继续--\n";
        system("pause>nul");
        system("cls");//clear screen,清屏;
        showMenu();
        cin >> select;
    }
    system("pause>nul");
    return 0;
}