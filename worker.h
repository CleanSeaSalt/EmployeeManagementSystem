//
// Created by xiaohai on 4/11/23.
//
#pragma once
#ifndef WORKER_H
#define WORKER_H

#include "bits/stdc++.h"
using namespace std;

// 抽象职工类
class Worker {
public:
    //显示个人信息
    virtual void Show_Info()=0;

    //获取部门名称，dept是department的缩写
    virtual string GetDeptName()=0;

    //获取职工编号编号
    virtual int GetID()=0;

    //获取职工姓名
    virtual string GetName()=0;

    //获取所在部门编号
    virtual int GetDeptID()=0;

    //设置部门名称
    virtual void SetDeptName(string DeptName)=0;

    //设置职工编号编号
    virtual void SetID(int ID)=0;

    //设置职工姓名
    virtual void SetName(string name)=0;

    //设置所在部门编号，dept是department的缩写
    virtual void SetDeptID(int DeptID)=0;

private:
    int ID;                     //职工编号
    string name;                //职工姓名
    string Deptname;            //岗位
    int DeptID;                 //所在部门编号


};


#endif //WORKER_H
