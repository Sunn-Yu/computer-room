#pragma once
#include<iostream>
using namespace std;
//身份基类
class Identity
{
public:
	//子类菜单
	virtual void operMenu() = 0;

	//用户姓名
	string m_name;


	//用户密码
	string m_pwd;
	
private:

};


