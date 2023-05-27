//
// Created by xiaohai on 4/11/23.
//

#include "WorkerManager.h"
#include "employee.h"

// 作用域::成员函数名
// WorkerManager的构造函数
WorkerManager::WorkerManager() {
    //1、文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        //cout << "文件不存在" << endl;
        SetEmpNum(0);
        SetEmpArray({});
        this->FileIsEmptyFlag = false;           //标志文件为空
        ifs.close();
        return;
    }

    //2、文件存在,但是文件内容为空,只读一个字符，如果这个字符是EOF，那么说明文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        //cout << "文件存在,但内容为空" << endl;
        SetEmpNum(0);
        SetEmpArray({});
        this->FileIsEmptyFlag = false;           //标志文件为空
        ifs.close();
        return;
    }

    //3、文件存在且不为空
    //获取文件中的数据，包含员工人数和员工信息
    this->GetEmpFileData();
    //cout << "文件存在，且内容不为空" << endl;

    //cout<<"其中职工人数有："<<this->num<<endl;
    //for(auto &worker:EmpArray)
    //{
    //    worker->Show_Info();
    //    //cout<<" 职工编号： "<<worker->GetID()<<" 职工姓名： "<<worker->GetName()<<" 部门编号： "<<worker->GetDeptID()<<endl;
    //}


};

WorkerManager::~WorkerManager() {
    EmpArray.clear();
};

void WorkerManager::Show_Menu() {
    cout << "*************************************************************************************" << endl;
    cout << "***************************欢迎使用职工管理系统*****************************************" << endl;
    cout << "***************************0.退出管理程序**********************************************" << endl;
    cout << "***************************1.增加职工信息**********************************************" << endl;
    cout << "***************************2.显示职工信息**********************************************" << endl;
    cout << "***************************3.删除离职职工**********************************************" << endl;
    cout << "***************************4.修改职工信息**********************************************" << endl;
    cout << "***************************5.查找职工信息**********************************************" << endl;
    cout << "***************************6.按照编号排序**********************************************" << endl;
    cout << "***************************7.清空所有文档**********************************************" << endl;
    cout << endl;
};

void WorkerManager::Exit_System() {
    cout << "欢迎您下次使用！" << endl;
    //system("pause");
    exit(0);
};

void WorkerManager::Add_Worker()             //添加员工
{
    cout << "请输入添加的职工数量:" << endl;
    int AddNum = 0;
    cin >> AddNum;
    if (AddNum > 0) {
        vector<Worker *> Emp = GetEmpArray();
        int NewSize = GetEmpNum() + AddNum;

        for (int i = 0; i < AddNum; i++) {
            int worker_id;                                     //编号
            string worker_name;                                //姓名
            int worker_dept;                                   //部门选择，dept是department的缩写

            cout << "请输入需要增加的第" << i + 1 << "个新职工编号" << endl;
            cin >> worker_id;

            int ret = IsWorkerExist(worker_id);
            if (ret != -1) {
                cout << "输入错误，该编号已存在！" << endl;
                return;
            }
            cout << "请输入需要增加的第" << i + 1 << "个新职工姓名" << endl;
            cin >> worker_name;

            cout << "请选择该职工的岗位" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、总裁" << endl;
            cin >> worker_dept;

            Worker *worker = nullptr;
            switch (worker_dept) {
                case 1:
                    worker = new Employee(worker_id, worker_name, worker_dept);
                    Emp.emplace_back(worker);
                    break;
                case 2:
                    worker = new Manager(worker_id, worker_name, worker_dept);
                    Emp.emplace_back(worker);
                    break;
                case 3:
                    worker = new Boss(worker_id, worker_name, worker_dept);
                    Emp.emplace_back(worker);
                    break;
                default:
                    break;
            }

        }
        //更新新空间的指向
        SetEmpArray(Emp);

        //更新职工人数
        SetEmpNum(NewSize);

        //更新文件标志
        this->FileIsEmptyFlag = true;

        //系统反馈，提示添加成功
        cout << "成功添加" << AddNum << "名新职工" << endl;

        //保存到文件中
        this->Save();
    } else {
        cout << "输入数据有误！" << endl;
        return;
    }

    //按任意键清屏，回到上级目录
    system("clear");
};

//显示员工
void WorkerManager::Show_Worker() {
    if (this->FileIsEmptyFlag == true) {
        cout << "文件存在且内容不为空！" << endl;
        cout << "其中职工人数有：" << this->num << endl;
        for (auto &worker: EmpArray) {
            worker->Show_Info();
            //cout << " 职工编号： " << worker->GetID() << " 职工姓名： " << worker->GetName() << " 部门编号： " << worker->GetDeptID() << endl;
        }
    } else {
        cout << "文件不存在或者内容为空！" << endl;
    }
    ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQDNtJTQZXaXbI4DX48uivjuo+Idx/VRzyqsp6r59qKGMJCvgWM37Ni8ijrQ0wNa7KsVUqO3n4NFzolDOnG5cWY4Vf5ounBE9J8NKdl7nqp0NjY6Tj7jYcGb8jGg4Ve2FPmLIpwXJWq87omDjj6Bw1h4EWNJ5pmplJIKUQibitQTegjFKBhqdU2s1gM5OpuMGZFm6Wff7yd5Lgu6PHjLzJA1M2FZNj1d7RgGBL4KP2n97x8RPFARuQ57kSFdZJ0oFHjVFNSCNr46PkStcEKGH6ynTkIZ33UNDKEtnRFbpBVycIIisN4RE16XvFUp0L0FMLZ2VDTx3fjfacsJlfD4jznXkZo6CsCRxtuwAdfTFfX61TSgExWqWqPbsIZxyZXe+7JAnCeDbhNntOd+qttwYbekw//0gk2xX70k3DH2ARqPr2z2NX+CAeQvel2PMgEIT3ylaqVJBmd03fHjEY4FBoMyPFdGGqwWmSAtAHAXbuXuccdxy01vekRDjphLzXuSRX8= 1635849067@qq.com

};

//删除员工信息
void WorkerManager::Del_Worker() {
    if (this->FileIsEmptyFlag == true) {

        cout << "请输入想要删除的员工编号:" << endl;
        int worker_id;
        cin >> worker_id;

        int ret = IsWorkerExist(worker_id);
        if (ret == -1) {
            cout << "不存在员工编号为" << worker_id << "的相关信息" << endl;
        } else {
            cout << "存在员工编号为" << worker_id << "的相关信息" << endl;
            vector<Worker *> New_EmpArry;
            for (auto &worker: EmpArray) {
                if (worker->GetID() == worker_id) {
                    continue;
                }
                New_EmpArry.emplace_back(worker);
            }
            SetEmpArray(New_EmpArry);
            SetEmpNum(int(New_EmpArry.size()));
            cout << "员工编号为" << worker_id << "的相关信息已被删除" << endl;
            Save();
        }
    } else {
        cout << "文件不存在或者内容为空" << endl;
    }
};

//修改文件中的员工
void WorkerManager::Mod_Worker() {
    if (this->FileIsEmptyFlag == true) {
        cout << "请输入要修改的职工编号" << endl;

        int worker_id;
        cin >> worker_id;

        int ret = IsWorkerExist(worker_id);
        if (ret == -1) {
            cout << "修改失败，不存在员工编号为" << worker_id << "的相关信息" << endl;
        } else {
            cout << "存在员工编号为" << worker_id << "的相关信息" << endl;
            int new_worker_id;
            string new_worker_name;
            int new_worker_dept;
            cout << "请更新该员工的编号：" << endl;
            cin >> new_worker_id;
            cout << "请更新该员工的姓名：" << endl;
            cin >> new_worker_name;
            cout << "请更新该员工的岗位：" << endl;
            cout << "1、普通职工：" << endl;
            cout << "2、经理：" << endl;
            cout << "3、总裁：" << endl;
            cin >> new_worker_dept;

            Worker *worker = nullptr;
            switch (new_worker_dept) {
                case 1:
                    worker = new Employee(new_worker_id, new_worker_name, new_worker_dept);
                    break;
                case 2:
                    worker = new Manager(new_worker_id, new_worker_name, new_worker_dept);
                    break;
                case 3:
                    worker = new Boss(new_worker_id, new_worker_name, new_worker_dept);
                    break;
                default:
                    break;
            }
            //更改数据
            this->EmpArray[ret] = worker;
            cout << "修改成功,员工编号为" << worker_id << "的相关信息已被修改" << endl;
            //保存到文件当中
            Save();
        }
    } else {
        cout << "文件不存在或者内容为空" << endl;
    }


};

//查找文件中的员工
void WorkerManager::Find_Worker() {
    //按照编号查找员工
    if (this->FileIsEmptyFlag == true) {
        cout << "请输入要查找的职工编号" << endl;

        int worker_id;
        cin >> worker_id;

        int ret = IsWorkerExist(worker_id);
        if (ret == -1) {
            cout << "查找失败，不存在员工编号为" << worker_id << "的相关信息" << endl;
        } else {
            cout << "存在员工编号为" << worker_id << "的相关信息" << endl;
            this->EmpArray[ret]->Show_Info();
        }
    } else {
        cout << "文件不存在或者内容为空" << endl;
    }
}

//将文件中的员工按照职工号排序（升序或者降序）
void WorkerManager::Sort_Worker() {
    //按照编号查找员工
    if (this->FileIsEmptyFlag == true) {
        cout << "请选择排序方式：" << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;
        int select;
        cin >> select;

        if (select == 1) {
            //升序
            sort(EmpArray.begin(), EmpArray.end(), cmp1());
        } else {
            //降序
            sort(EmpArray.begin(), EmpArray.end(), cmp2());
        }
        cout << "排序成功" << endl;

        //保存文件
        Save();

    } else {
        cout << "文件不存在或者内容为空" << endl;
    }
};

//清空所有文档
void WorkerManager::Clear_Worker_File() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;
    if (select == 1) {
        //打开模式，ios::trunc 如果存在，则删除文件并重新创建一个文件
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        SetEmpNum(0);
        this->EmpArray.clear();
        this->FileIsEmptyFlag = false;

        cout << "清空成功" << endl;
    }

};

//判断员工是否存在函数
int WorkerManager::IsWorkerExist(int worker_id) {
    int index = -1;
    for (int i = 0; i < this->EmpArray.size(); i++) {
        if (EmpArray[i]->GetID() == worker_id) {
            index = i;
            break;
        }
    }
    return index;
};

void WorkerManager::Save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    //员工：员工数组
    for (auto &worker: EmpArray) {
        //员工ID 员工姓名 员工所在部门编号
        //cout << employee->GetID() << " " << employee->GetName() << " " << employee->GetDeptID() << endl;
        ofs << worker->GetID() << " " << worker->GetName() << " " << worker->GetDeptID() << endl;
    }
    cout << "文件已更新！" << endl;

};

//获取职工人数
int WorkerManager::GetEmpNum() {
    return num;
};

//获取employee_file.txt文件中已存储的员工人数
void WorkerManager::GetEmpFileData() {
    ifstream ifs;

    ifs.open(FILENAME, ios::in);

    int worker_id;
    string worker_name;
    int worker_dept;
    int worker_num = 0;
    vector<Worker *> woker_array;

    while (ifs >> worker_id && ifs >> worker_name && ifs >> worker_dept) {
        //cout<<worker_id<<" "<<worker_name<<" "<<worker_dept<<endl;
        //更新员工数量
        worker_num++;
        //根据员工所在部门，新建职工对象并插入到EmpArry当中
        switch (worker_dept) {
            case 1:
                //普通员工
                woker_array.emplace_back(new Employee(worker_id, worker_name, worker_dept));
                break;
            case 2:
                //经理
                woker_array.emplace_back(new Manager(worker_id, worker_name, worker_dept));
                break;
            case 3:
                //总裁
                woker_array.emplace_back(new Boss(worker_id, worker_name, worker_dept));
                break;
            default:
                break;
        }
    }

    SetEmpNum(worker_num);
    SetEmpArray(woker_array);
    ifs.close();

};

//获取职工数组指针
vector<Worker *> WorkerManager::GetEmpArray() {
    return this->EmpArray;
};

//设置职工人数
void WorkerManager::SetEmpNum(int num) {
    this->num = num;
};

//设置职工数组指针
void WorkerManager::SetEmpArray(vector<Worker *> EmpArray) {
    this->EmpArray = EmpArray;
};


