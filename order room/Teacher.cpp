#include"Teacher.h"

void TeacherMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Teacher* ter = (Teacher*)manager;

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
			// 1.�鿴����ԤԼ
			/*cout << "1" << endl;*/
			ter->showAllOrder();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			// 2.���ԤԼ
			/*cout << "2" << endl;*/
			ter->validOrder();
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
Teacher::Teacher()
{

}
//�вι���
Teacher::Teacher(int Tnum, string name, string pwd)
{
	this->Tnum = Tnum;
	this->m_name = name;
	this->m_pwd = pwd;
}

//��ʦ�˵�
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ" << this->m_name << "��¼!" << endl;
	cout << "\t\t-------------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                1.�鿴����ԤԼ                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                2.���ԤԼ                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                0.ע����¼                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t-------------------------------------------------------\n";
	cout << "����������ѡ��" << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
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
		cout << "ԤԼѧ��������" << o.m_OrderData[i]["name"] << "   ";
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

//���ԤԼ
void Teacher::validOrder()
{
	Order o;
	if (o.m_Size == 0)
	{
		cout << "����Ҫ��˼�¼" << endl;
		return;
	}
	else
	{
		vector<int> v;
		int index=0;
		cout << "�������¼�¼��Ҫ��ˣ�" << endl;
		for (int i = 0; i < o.m_Size; i++)
		{
			if (o.m_OrderData[i]["status"] == "1")
			{
				v.push_back(i);
				cout << ++index << "��";
				cout << "������" << o.m_OrderData[i]["name"] << "   ";
				cout << "ԤԼ���ڣ� ��" << o.m_OrderData[i]["data"] << "   ";
				cout << "ԤԼʱ�Σ�" << (o.m_OrderData[i]["time"] == "1" ? "����" : "����") << "   ";
				cout << "ԤԼ������ţ�" << o.m_OrderData[i]["room"] << endl;
			}
		}
		cout << "��������˵�ԤԼ��¼��ţ�0������" << endl;
		int chose;
		
		while (true)
		{
			cin >> chose;
			if (chose >= 0 && chose <= v.size())
			{
				if (chose == 0)
				{
					break;
				}
				else
				{
					cout << "��������˽��" << endl;
					cout << "1.ͨ��" << endl;
					cout << "2.��ͨ��" << endl;
					int ret;
					cin >> ret;
					if (ret == 1)
					{
						o.m_OrderData[v[chose - 1]]["status"] = "2";
					}
					else
					{
						o.m_OrderData[v[chose - 1]]["status"] = "-1";
					}
					cout << "��������" << endl;
					o.UpdataOrder();
					break;
				}
		    }
			else
			{
				cout << "���������룺" << endl;
			}
		}
		
	}
}