#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include"globalFile.h"
#include<string>
class Order
{
public:
	//构造函数
	Order();
	
	//更新函数；
	void UpdataOrder();

	//初始化预约信息
	void InitOrder();

	//记录预约条数
	int m_Size;

	//记录预约信息的容器 key 个数 value 信息
	map<int, map<string, string>> m_OrderData;
};
