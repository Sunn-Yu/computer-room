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
//����ѧ����
class Student:public Identity
{
public:
	//�޲ι���
	Student();
	//�вι��� ѧ�� ���� ����
	Student(int Snum, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//��ʼ��������Ϣ
	void InitComputer();

	//����������Ϣ����
	vector<Computer> vCom;
	//ѧ��ѧ��
	int Snum;
private:

};


