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
		cout << "文件不存在" << endl;
		ifs.close();
		return ;
	}

	int num = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入您的学号" << endl;
		cin >> num;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号" << endl;
		cin >> num;
	}

	cout << "请输入您的用户名" << endl;
	cin >> name;
	cout << "请输入您的密码" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生身份验证
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
				cout << "学生" << fname << "登录成功！" << endl;

				
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
		//老师身份验证
		
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
				cout << "老师" << fname << "登录成功！" << endl;
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
		//管理员身份验证
		string fname;
		string fpwd;

		while ( ifs >> fname && ifs >> fpwd)
		{
			if ( fname == name && fpwd == pwd)
			{
				cout << "管理员" << fname << "登录成功！" << endl;

				system("pause");
				system("cls");
				Person=new Manager(name, pwd);
				ManageraMenu(Person);
			
				return;
			}
		}
	}
	cout << "验证登录失败" << endl;

	system("pause");
	system("cls");
	return;
}
int main()
{
	
	while (true)
	{
		cout << "********************欢迎来到机房预约系统****************************" << endl;
		cout << endl;
		cout << "请输入您的身份" << endl;
		cout << "\t\t-------------------------------------------------------\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                1.学生代表                           |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                2.老    师                           |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                3.管 理 员                           |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                0.退   出                            |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t-------------------------------------------------------\n";
		cout << "请输入您的选择：";
		int chose;
		cin >> chose;
		switch (chose)
		{
		case 1://学生
			/*cout << 1;*/
			loginIn(StudentFile, 1);
			break;
		case 2://老师
			/*cout << 2;*/
			loginIn(TeacherFile, 2);
			break;
		case 3://管理员
			loginIn(AdminFile, 3);
			/*cout << 3;*/
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;


		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0;
}