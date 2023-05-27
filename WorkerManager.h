//
// Created by xiaohai on 4/11/23.
//
#pragma once                       //防止头文件重复包含
#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "bits/stdc++.h"

using namespace std;

#define FILENAME "employee_file.txt"

class WorkerManager {
public:
    WorkerManager();            //构造函数
    ~WorkerManager();           //析构函数

    void Show_Menu();           //显示菜单
    void Exit_System();         //退出系统
    void Add_Worker();          //添加员工信息
    void Show_Worker();         //显示员工信息
    void Del_Worker();          //删除文件中的员工信息
    void Mod_Worker();          //修改文件中的员工
    void Find_Worker();         //查找文件中的员工
    void Sort_Worker();         //将文件中的员工按照职工号排序（升序或者降序）
    void Clear_Worker_File();        //清空所有文档

    int IsWorkerExist(int worker_id);        //判断员工是否存在函数,存在返回索引，不存在返回-1
    void Save();                          //保存文件到FILENAME中

    bool FileIsEmptyFlag;                 //标志文件是否为空

    int GetEmpNum();                      //获取职工人数
    void GetEmpFileData();                //获取文件中已存储的员工人数

    vector<Worker *> GetEmpArray();      //获取职工数组

    void SetEmpNum(int num);                         //设置职工人数
    void SetEmpArray(vector<Worker *> EmpArray);     //设置职工数组指针

private:
    int num;                             //记录职工人数
    vector<Worker *> EmpArray;          //职工数组
};

//以函数对象的方式实现自定义排序规则
//升序
class cmp1 {
public:
    bool operator()(Worker* worker1,Worker* worker2)
    {
        return (worker1->GetID() < worker2->GetID());
    }
};

//降序
class cmp2 {
public:
    bool operator()(Worker* worker1,Worker* worker2)
    {
        return (worker1->GetID() > worker2->GetID());
    }
};


#endif //WORKERMANAGER_H
