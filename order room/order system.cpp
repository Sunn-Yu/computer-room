#include<iostream>
using namespace std;
#include<fstream>
#include"Identity.h"
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
void loginIn(string FileName, int type)
{
	Identity* Person = NULL;
	ifstream ifs;
	ifs.open(FileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return ;
	}

	int num = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "����������ѧ��" << endl;
		cin >> num;
	}
	else if (type == 2)
	{
		cout << "����������ְ����" << endl;
		cin >> num;
	}

	cout << "�����������û���" << endl;
	cin >> name;
	cout << "��������������" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ�������֤
		int fnum;
		string fname;
		string fpwd;

		while (ifs >> fnum && ifs >> fname && ifs >> fpwd)
		{
			/*cout << fnum << endl;
			cout << fname << endl;
			cout << fpwd << endl;*/
			if (fnum == num && fname == name && fpwd == pwd)
			{
				cout << "ѧ��" << fname << "��¼�ɹ���" << endl;

				
				system("pause");
				system("cls");
				Person = new Student(num, name, pwd);
				StudentMenu(Person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		//��ʦ�����֤
		
		int fnum;
		string fname;
		string fpwd;

		while (ifs >> fnum && ifs >> fname && ifs >> fpwd)
		{
			/*cout << fnum << endl;
			cout << fname << endl;
			cout << fpwd << endl;*/
			if (fnum == num && fname == name && fpwd == pwd)
			{
				cout << "��ʦ" << fname << "��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				Person=new Teacher(num, name, pwd);
				TeacherMenu(Person);
			
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fname;
		string fpwd;

		while ( ifs >> fname && ifs >> fpwd)
		{
			if ( fname == name && fpwd == pwd)
			{
				cout << "����Ա" << fname << "��¼�ɹ���" << endl;

				system("pause");
				system("cls");
				Person=new Manager(name, pwd);
				ManageraMenu(Person);
			
				return;
			}
		}
	}
	cout << "��֤��¼ʧ��" << endl;

	system("pause");
	system("cls");
	return;
}
int main()
{
	
	while (true)
	{
		cout << "********************��ӭ��������ԤԼϵͳ****************************" << endl;
		cout << endl;
		cout << "�������������" << endl;
		cout << "\t\t-------------------------------------------------------\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                1.ѧ������                           |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                2.��    ʦ                           |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                3.�� �� Ա                           |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                0.��   ��                            |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t-------------------------------------------------------\n";
		cout << "����������ѡ��";
		int chose;
		cin >> chose;
		switch (chose)
		{
		case 1://ѧ��
			/*cout << 1;*/
			loginIn(StudentFile, 1);
			break;
		case 2://��ʦ
			/*cout << 2;*/
			loginIn(TeacherFile, 2);
			break;
		case 3://����Ա
			loginIn(AdminFile, 3);
			/*cout << 3;*/
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;


		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}