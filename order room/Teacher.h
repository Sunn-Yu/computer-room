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
	//�޲ι���
	Teacher();
	//�вι���
	Teacher(int Tnum, string name, string pwd);

	//��ʦ�˵�
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦְ����
	int Tnum;
};

