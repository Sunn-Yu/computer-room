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
//����Ա�ӿ�
void ManageraMenu(Identity*& manager);
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager( string name, string pwd);

	//����Ա�˵�ʵ��
	virtual void operMenu();

	//�����˺�
	void AddPerson();

	//  �鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void InitVector();

	//��ȡ������Ϣ
	void InitComputer();

	//������id�Ƿ��ظ� ѧ�� ����
	//������ �ظ�
	bool checkRepeat(int id,int type);


	

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<Computer> vCom;

};
