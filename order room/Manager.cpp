#include"Manager.h"


void ManageraMenu(Identity *   &manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;

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
			// 1.����˺�
			/*cout << "1" << endl;*/
			man->AddPerson();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			// 2.�鿴�˺�
			/*cout << "2" << endl;*/
			man->showPerson();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			/*cout << "3" << endl;*/
			// 3.�鿴����
			man->showComputer();
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			//4.���ԤԼ 
			/*cout << "4" << endl;*/
			man->cleanFile();
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
//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
	//��ʼ������ ��ȡ�ļ�������Ϣ
	this->InitVector();
	//��ʼ��������Ϣ
	this->InitComputer();
}

//����Ա�˵�ʵ��
void Manager::operMenu()
{
	cout << "��ӭ����Ա" << this->m_name << "��¼" << endl;
	cout << "\t\t-------------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                1.����˺�                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                2.�鿴�˺�                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                3.�鿴����                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                4.���ԤԼ                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                0.ע����¼                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t-------------------------------------------------------\n";
	cout << "����������ѡ��" << endl;

}

//�����˺�
void Manager::AddPerson()
{
	cout << "��ѡ��������Ա��ݣ�" << endl;
	cout << "1-ѧ��" << endl;
	cout << "2-��ʦ" << endl;
	int chose = 0;
	cin >> chose;
	int num=0;
	string name;
	string pwd;
	string Filename;
	string tip;
	string errorTip;
	if (chose == 1)
	{
		Filename = StudentFile;
		tip = "ѧ��";
		errorTip = "ѧ���ظ������������룡";
	}
	else
	{
		Filename = TeacherFile;
		tip = "ְ�����";
		errorTip = "ְ�����ظ������������룡";
	}

	while (true)
	{
		cout << "������" << tip  <<":"<<endl;
		cin >> num;
		if (this->checkRepeat(num, chose))
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
		
	}
	cout << "��������û�����" << endl;
	cin >> name;
	cout << "��������û�����" << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(Filename,ios::out|ios::app);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
	}
	ofs << num << " " << name << " " << pwd <<" "<<endl;
	cout << "��ӳɹ�" << endl;

	

	ofs.close();
	this->InitVector();
}
//��ӡѧ����Ϣ
void printStu(Student& s)
{
	cout << "ѧ�ţ�" << s.Snum << "ѧ��������" << s.m_name << "ѧ�����룺" << s.m_pwd << endl;


}
//��ӡ��ʦ��Ϣ
void printTea(Teacher& t)
{

	cout << "ְ���ţ�" << t.Tnum << "��ʦ������" << t.m_name << "��ʦ���룺" << t.m_pwd << endl;

}

//  �鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ������鿴�˺����ͣ�" << endl;
	cout << "1-ѧ��" << endl;
	cout << "2-��ʦ" << endl;
	int chose = 0;
	cin >> chose;
	if (chose == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStu);
	}
	else 
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTea);
	}
}


//��ȡ������Ϣ
void Manager::InitComputer()
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


//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<Computer>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_id << "�����������:" << it->m_MaxSize << endl;
	}
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	cout << "��ȷ���������ԤԼ��Ϣ��" << endl;
	cout << "1-ȷ��" << endl;
	cout << "2-ȡ��" << endl;
	int chose = 0;
	cin >> chose;
	if (chose == 1)
	{
		ofstream ofs;
		ofs.open(OrderFile, ios::trunc);
		ofs.close();
		cout << "ԤԼ��Ϣ�����" << endl;
	}
	else
	{
		return;
	}
	return;
}
//��ʼ������
void Manager::InitVector()
{
	ifstream ifs;
	ifs.open(StudentFile, ios::in);

	if (!ifs.is_open())
	{
		cout << "ѧ���ļ���ʧ��" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();
	Student s;
	while (ifs >> s.Snum && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	//cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();
	ifs.open(TeacherFile, ios::in);
	Teacher t;
	if (!ifs.is_open())
	{
		cout << "��ʦ�ļ���ʧ��" << endl;
		return;
	}
	while (ifs >> t.Tnum && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	/*cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;*/
	ifs.close();
}

//������id�Ƿ��ظ�
bool Manager::checkRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == (*it).Snum)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == (*it).Tnum)
			{
				return true;
			}
		}
	}
	return false;
}
