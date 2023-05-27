#include <iostream>
#include "WorkerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "bits/stdc++.h"

using namespace std;

void test()
{
    Worker *worker0 = new Employee(1, "张三", 1);
    worker0->Show_Info();
    delete worker0;

    Worker *worker1 = new Manager(2, "李四", 2);
    worker1->Show_Info();
    delete worker1;

    Worker *worker2 = new Boss(3, "王麻子", 3);
    worker2->Show_Info();
    delete worker2;

};


int main()
{
    //实例化管理者对象
    WorkerManager WM;

    system("chcp 65001"); //为了解决命令行显示中文乱码
    
    int choice = 0;

    //测试
    //test();
    while (true)
    {
        //调用显示菜单成员函数
        WM.Show_Menu();

        //交互
        cout << "请输入您的选择：" << endl;
        cin >> choice;

        switch (choice)
        {
            case 0:                     //退出系统
                WM.Exit_System();
                break;
            case 1:                     //增加员工信息
                WM.Add_Worker();
                break;
            case 2:                     //显示职工信息
                WM.Show_Worker();
                break;
            case 3:                     //删除职工
            {
                //case里面需要添加代码块才能定义变量
                WM.Del_Worker();
            }
                break;
            case 4:                     //修改职工
                WM.Mod_Worker();
                break;
            case 5:                     //查找职工
                WM.Find_Worker();
                break;
            case 6:                     //排序职工
                WM.Sort_Worker();
                break;
            case 7:                     //清空文档
                WM.Clear_Worker_File();
                break;
            default:
                system("cls");
                break;
        }
        system("cls");

    }


    return 0;
}
