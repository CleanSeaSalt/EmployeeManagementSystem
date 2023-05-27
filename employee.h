//
// Created by xiaohai on 4/11/23.
//
#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "worker.h"

class Employee: public Worker
{
public:
    //构造函数
    Employee(int ID,string name,int DeptID);

    //显示个人信息
    virtual void Show_Info();

    //获取部门名称，dept是department的缩写
    virtual string GetDeptName();

    //获取职工编号编号
    virtual int GetID();

    //获取职工姓名
    virtual string GetName();

    //获取所在部门编号
    virtual int GetDeptID();

    //设置部门名称
    virtual void SetDeptName(string DeptName);

    //设置职工编号编号
    virtual void SetID(int ID);

    //设置职工姓名
    virtual void SetName(string name);

    //设置所在部门编号，dept是department的缩写
    virtual void SetDeptID(int DeptID);

private:
    int ID;                     //职工编号
    string name;                //职工姓名
    string Deptname;            //岗位
    int DeptID;                 //所在部门编号
};


#endif //EMPLOYEEMANAGEMENTSYSTEM_EMPLOYEE_H
