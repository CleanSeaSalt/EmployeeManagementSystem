//
// Created by xiaohai on 4/11/23.
//

#include "manager.h"

//构造函数
Manager::Manager(int ID,string name,int DeptID)
{
    SetID(ID);
    SetName(name);
    SetDeptID(DeptID);
    SetDeptName("经理");
};

//显示个人信息
void Manager::Show_Info()
{
    cout<<"职工编号："<<GetID()<<"\t职工姓名："<<GetName()<<"\t岗位："<<GetDeptName()<<"\t岗位职责：完成老板交给的任务，并将任务拆分下发给员工"<<endl;
};

//获取部门名称，dept是department的缩写
string Manager::GetDeptName()
{
    return Deptname;
};

//获取职工编号编号
int Manager::GetID()
{
    return ID;
};

//获取职工姓名
string Manager::GetName()
{
    return name;
};

//获取所在部门编号
int Manager::GetDeptID()
{
    return DeptID;
};

//设置部门名称
void Manager::SetDeptName(string DeptName)
{
    this->Deptname=DeptName;
};

//设置职工编号编号
void Manager::SetID(int ID)
{
    this->ID=ID;
};

//设置职工姓名
void Manager::SetName(string name)
{
    this->name=name;
};

//设置所在部门编号，dept是department的缩写
void Manager::SetDeptID(int DeptID)
{
    this->DeptID=DeptID;
};