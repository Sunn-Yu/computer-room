#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"Computer.h"
#include<vector>
#include<fstream>
#include"globalFile.h"
#include<string>
#include"Order.h"
void StudentMenu(Identity*& manager);
//创建学生类
class Student:public Identity
{
public:
	//无参构造
	Student();
	//有参构造 学号 姓名 密码
	Student(int Snum, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//初始化机房信息
	void InitComputer();

	//创建机房信息容器
	vector<Computer> vCom;
	//学生学号
	int Snum;
private:

};


