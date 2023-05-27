//
// Created by xiaohai on 4/11/23.
//

#include "employee.h"

//构造函数
Employee::Employee(int ID,string name,int DeptID)
{
    SetID(ID);
    SetName(name);
    SetDeptID(DeptID);
    SetDeptName("员工");
};

//显示个人信息
void Employee::Show_Info()
{
    cout<<"职工编号："<<GetID()<<"\t职工姓名："<<GetName()<<"\t岗位："<<GetDeptName()<<"\t岗位职责：完成经理交给的任务"<<endl;
};

//获取部门名称，dept是department的缩写
string Employee::GetDeptName()
{
    return Deptname;
};

//获取职工编号编号
int Employee::GetID()
{
    return ID;
};

//获取职工姓名
string Employee::GetName()
{
    return name;
};

//获取所在部门编号
int Employee::GetDeptID()
{
    return DeptID;
};

//设置部门名称
void Employee::SetDeptName(string DeptName)
{
    this->Deptname=DeptName;
};

//设置职工编号编号
void Employee::SetID(int ID)
{
    this->ID=ID;
};

//设置职工姓名
void Employee::SetName(string name)
{
    this->name=name;
};

//设置所在部门编号，dept是department的缩写
void Employee::SetDeptID(int DeptID)
{
    this->DeptID=DeptID;
};