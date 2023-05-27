//
// Created by xiaohai on 4/11/23.
//
#include "boss.h"

//构造函数
Boss::Boss(int ID,string name,int DeptID)
{
    SetID(ID);
    SetName(name);
    SetDeptID(DeptID);
    SetDeptName("总裁");
};

//显示个人信息
void Boss::Show_Info()
{
    cout<<"职工编号："<<GetID()<<"\t职工姓名："<<GetName()<<"\t岗位："<<GetDeptName()<<"\t岗位职责：总览公司所有事务"<<endl;
};

//获取部门名称，dept是department的缩写
string Boss::GetDeptName()
{
    return Deptname;
};

//获取职工编号编号
int Boss::GetID()
{
    return ID;
};

//获取职工姓名
string Boss::GetName()
{
    return name;
};

//获取所在部门编号
int Boss::GetDeptID()
{
    return DeptID;
};

//设置部门名称
void Boss::SetDeptName(string DeptName)
{
    this->Deptname=DeptName;
};

//设置职工编号编号
void Boss::SetID(int ID)
{
    this->ID=ID;
};

//设置职工姓名
void Boss::SetName(string name)
{
    this->name=name;
};

//设置所在部门编号，dept是department的缩写
void Boss::SetDeptID(int DeptID)
{
    this->DeptID=DeptID;
};