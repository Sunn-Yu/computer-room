#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"globalFile.h"
#include<fstream>
#include"Student.h"
#include"Teacher.h"
#include<vector>
#include<algorithm>
#include"Computer.h"
//管理员接口
void ManageraMenu(Identity*& manager);
class Manager :public Identity
{
public:
	//默认构造
	Manager();

	//有参构造
	Manager( string name, string pwd);

	//管理员菜单实现
	virtual void operMenu();

	//增加账号
	void AddPerson();

	//  查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器
	void InitVector();

	//读取机房信息
	void InitComputer();

	//检测添加id是否重复 学号 类型
	//返回真 重复
	bool checkRepeat(int id,int type);


	

	//学生容器
	vector<Student> vStu;

	//老师容器
	vector<Teacher> vTea;

	//机房容器
	vector<Computer> vCom;

};
