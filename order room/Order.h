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
	//���캯��
	Order();
	
	//���º�����
	void UpdataOrder();

	//��ʼ��ԤԼ��Ϣ
	void InitOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼ԤԼ��Ϣ������ key ���� value ��Ϣ
	map<int, map<string, string>> m_OrderData;
};
