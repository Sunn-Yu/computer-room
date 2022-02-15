#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"Order.h";
#include<vector>
void TeacherMenu(Identity*& manager);
class Teacher:public Identity
{
public:
	//无参构造
	Teacher();
	//有参构造
	Teacher(int Tnum, string name, string pwd);

	//老师菜单
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//老师职工号
	int Tnum;
};

