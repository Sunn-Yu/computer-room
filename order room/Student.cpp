#include"Student.h"


void StudentMenu(Identity *  &manager)
{
	while (true)
	{
		manager->operMenu();
		Student* stu = (Student*)manager;

		int chose = 0;
		cin >> chose;
		switch (chose)
		{
		case 0:
			//0.ע����¼
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		case 1:
		{
			// 1.����ԤԼ
			/*cout << "1" << endl;*/
			stu->applyOrder();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			// 2.�鿴�ҵ�ԤԼ
			/*cout << "2" << endl;*/
			stu->showMyOrder();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			/*cout << "3" << endl;*/
			// 3.�鿴����ԤԼ
			stu->showAllOrder();
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			//4.ȡ��ԤԼ
			/*cout << "4" << endl;*/
			stu->cancelOrder();
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			cout << "����������";
			system("pause");
			system("cls");
			break;
		}
		}

	}
	
}
//�޲ι���
Student::Student()
{

}
//�вι��� ѧ�� ���� ����
Student::Student(int num, string name, string pwd)
{
	this->Snum = num;
	this->m_name = name;
	this->m_pwd = pwd;

	this->InitComputer();
}



//�˵�����
 void Student::operMenu()
{

	 cout << "��ӭѧ��" << this->m_name << "��¼!" << endl;
	 cout << "\t\t-------------------------------------------------------\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                1.����ԤԼ                           |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                2.�鿴�ҵ�ԤԼ                       |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                3.�鿴����ԤԼ                       |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                4.ȡ��ԤԼ                           |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                0.ע����¼                           |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t-------------------------------------------------------\n";
	 cout << "����������ѡ��" << endl;
}

//����ԤԼ
 void Student::applyOrder()
 {
	 cout << "��������ʱ��Ϊ��һ������" << endl;
	 cout << "��ѡ������ԤԼʱ��" << endl;
	 cout << "1-��һ" << endl;
	 cout << "2-�ܶ�" << endl;
	 cout << "3-����" << endl;
	 cout << "4-����" << endl;
	 cout << "5-����" << endl;
	 int data = 0;
	 while (true)
	 {
		 cin >> data;
		 if (data > 0 && data < 6)
		 {
			 break;
		 }
		 else
		 {
			 cout << "�����������������룺" << endl;
		 }
	 }
	 cout << "��ѡ������ԤԼ��ʱ�䣺" << endl;
	 cout << "1-����" << endl;
	 cout << "2-����" << endl;
	 int time = 0;
	 while (true)
	 {
		 cin >> time;
		 if (time > 0 && time < 3)
		 {
			 break;
		 }
		 else
		 {
			 cout << "����������:" << endl;
		 }
	 }
	 cout << "��ѡ�������" << endl;
	 cout << "һ�Ż�������Ϊ��" << vCom[0].m_MaxSize << endl;
	 cout << "���Ż�������Ϊ��" << vCom[1].m_MaxSize << endl;
	 cout << "���Ż�������Ϊ��" << vCom[2].m_MaxSize << endl;
	 cout << "1-1�Ż���" << endl;
	 cout << "2-2�Ż���" << endl;
	 cout << "3-3�Ż���" << endl;
	 int room=0;
	 while (true)
	 {
		 cin >> room;
		 if (room > 0 && room < 4)
		 {
			 break;
		 }
		 else
		 {
			 cout << "��������������������" << endl;
		 }
	 }

	 cout << "ԤԼ�ɹ������" << endl;

	 ofstream ofs;
	 ofs.open(OrderFile, ios::app);
	 if (!ofs.is_open())
	 {
		 cout << "�洢ѧ��������Ϣ�򲻿��ļ���" << endl;
	 }
	 ofs << "name:" << this->m_name << " " << "data:" << data << " "
		 << "time:" << time << " " << "room:" << room << " "
		 << "sId:" << this->Snum << " " << "status:" << 1 << endl;
	 ofs.close();
 }

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	Order o;
	if (o.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < o.m_Size; i++)
	{
		if (atoi(o.m_OrderData[i]["sId"].c_str()) == this->Snum)
		{
			cout << "ԤԼ���ڣ� ��" << o.m_OrderData[i]["data"]  << "   ";
			cout << "ԤԼʱ�Σ�" << (o.m_OrderData[i]["time"] == "1" ? "����" : "����" )<< "   ";
			cout << "ԤԼ������ţ�" << o.m_OrderData[i]["room"] << "   ";
			cout << "����ԤԼ";
			string status = "״̬��";
			if (o.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (o.m_OrderData[i]["status"] == "2")
			{
				status += "��ԤԼ";
			}
			if (o.m_OrderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			if (o.m_OrderData[i]["status"] == "0")
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
			
	}

}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	Order o;
	if (o.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < o.m_Size; i++)
	{
		cout << "ԤԼѧ��������" << o.m_OrderData[i]["name"] <<"   ";
		cout << "ԤԼ���ڣ� ��" << o.m_OrderData[i]["data"] << "   ";
		cout << "ԤԼʱ�Σ�" << (o.m_OrderData[i]["time"] == "1" ? "����" : "����") << "   ";
		cout << "ԤԼ������ţ�" << o.m_OrderData[i]["room"] << "   ";
		cout << "ԤԼ";
		string status = "״̬��";
			if (o.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (o.m_OrderData[i]["status"] == "2")
			{
				status += "��ԤԼ";
			}
			if (o.m_OrderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			if (o.m_OrderData[i]["status"] == "0")
			{
				status += "ԤԼ��ȡ��";
			}
		cout << status << endl;
	}
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	Order o;
	if (o.m_Size == 0)
	{
		cout << "��ԤԼ��Ϣ" << endl;
		return;
	}
	cout << "��������ԤԼ��¼���Ը��ģ�" << endl;
	vector<int>v;
	int indx = 1;
	for (int i = 0; i < o.m_Size; i++)
	{
		if (this->Snum == atoi(o.m_OrderData[i]["sId"].c_str()))
		{
			if (o.m_OrderData[i]["status"] == "1" || o.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
			
				cout << indx++ << "��";
				cout << "ԤԼ���ڣ� ��" << o.m_OrderData[i]["data"] <<"   ";
				cout << "ԤԼʱ�Σ�" << (o.m_OrderData[i]["time"] == "1" ? "����" : "����") << "   ";
				cout << "ԤԼ������ţ�" << o.m_OrderData[i]["room"] << "   ";
				string status = "ԤԼ״̬��";
				if (o.m_OrderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (o.m_OrderData[i]["status"] == "2")
				{
					status += "��ԤԼ";
				}
				if (o.m_OrderData[i]["status"] == "-1")
				{
					status += "ԤԼʧ��";
				}
				if (o.m_OrderData[i]["status"] == "0")
				{
					status += "ԤԼ��ȡ��";
				}
				cout << status << endl;

			}
			else
			{
				cout << "����ԤԼ�޷�ȡ��" << endl;
			}
		}
		
	}
	cout << "����������Ҫȡ����ԤԼ���,0������" << endl;
	int chose;
	while (true)
	{
		cin >> chose;
		if (chose == 0)
		{
			break;
		}
        else if (chose > 0 && chose <= v.size())
		{
			o.m_OrderData[v[chose - 1]]["status"] = "0";
			o.UpdataOrder();
			cout << "��ȡ����ԤԼ" << endl;
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	

}
//��ȡ������Ϣ
void Student::InitComputer()
{
	vCom.clear();
	ifstream ifs;
	ifs.open(ComputerFile, ios::in);
	if (!ifs.is_open())
	{
		cout << "�����ļ��޷��򿪣�" << endl;
		return;
	}
	Computer c;
	while (ifs >> c.m_id && ifs >> c.m_MaxSize)
	{
		vCom.push_back(c);
	}
	ifs.close();
}