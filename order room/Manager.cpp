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
			//0.注销登录
		{
		delete manager;
		cout << "注销成功" << endl;
		system("pause");
		system("cls");
		return;
		}
		case 1:
		{
			// 1.添加账号
			/*cout << "1" << endl;*/
			man->AddPerson();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			// 2.查看账号
			/*cout << "2" << endl;*/
			man->showPerson();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			/*cout << "3" << endl;*/
			// 3.查看机房
			man->showComputer();
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			//4.清空预约 
			/*cout << "4" << endl;*/
			man->cleanFile();
			system("pause");
			system("cls");
			break;
		}
		default:
		{
			cout << "您输入有误！";
			system("pause");
			system("cls");
			break;
		}
		}
		
	}
}
//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
	//初始化容器 获取文件所有信息
	this->InitVector();
	//初始化机房信息
	this->InitComputer();
}

//管理员菜单实现
void Manager::operMenu()
{
	cout << "欢迎管理员" << this->m_name << "登录" << endl;
	cout << "\t\t-------------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                1.添加账号                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                2.查看账号                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                3.查看机房                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                4.清空预约                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                0.注销登录                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t-------------------------------------------------------\n";
	cout << "请输入您的选择：" << endl;

}

//增加账号
void Manager::AddPerson()
{
	cout << "请选择增加人员身份：" << endl;
	cout << "1-学生" << endl;
	cout << "2-老师" << endl;
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
		tip = "学号";
		errorTip = "学号重复，请重新输入！";
	}
	else
	{
		Filename = TeacherFile;
		tip = "职工编号";
		errorTip = "职工号重复，请重新输入！";
	}

	while (true)
	{
		cout << "请输入" << tip  <<":"<<endl;
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
	cout << "请输入该用户姓名" << endl;
	cin >> name;
	cout << "请输入该用户密码" << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(Filename,ios::out|ios::app);
	if (!ofs.is_open())
	{
		cout << "文件打开失败！" << endl;
	}
	ofs << num << " " << name << " " << pwd <<" "<<endl;
	cout << "添加成功" << endl;

	

	ofs.close();
	this->InitVector();
}
//打印学生信息
void printStu(Student& s)
{
	cout << "学号：" << s.Snum << "学生姓名：" << s.m_name << "学生密码：" << s.m_pwd << endl;


}
//打印老师信息
void printTea(Teacher& t)
{

	cout << "职工号：" << t.Tnum << "老师姓名：" << t.m_name << "老师密码：" << t.m_pwd << endl;

}

//  查看账号
void Manager::showPerson()
{
	cout << "请选择您想查看账号类型！" << endl;
	cout << "1-学生" << endl;
	cout << "2-老师" << endl;
	int chose = 0;
	cin >> chose;
	if (chose == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStu);
	}
	else 
	{
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTea);
	}
}


//读取机房信息
void Manager::InitComputer()
{
	vCom.clear();
	ifstream ifs;
	ifs.open(ComputerFile, ios::in);
	if (!ifs.is_open())
	{
		cout << "机房文件无法打开！" << endl;
		return;
	}
	Computer c;
	while (ifs >> c.m_id && ifs >> c.m_MaxSize)
	{
		vCom.push_back(c);
	}
	ifs.close();
}


//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<Computer>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_id << "机房最大容量:" << it->m_MaxSize << endl;
	}
}

//清空预约记录
void Manager::cleanFile()
{
	cout << "您确定清空所有预约信息？" << endl;
	cout << "1-确定" << endl;
	cout << "2-取消" << endl;
	int chose = 0;
	cin >> chose;
	if (chose == 1)
	{
		ofstream ofs;
		ofs.open(OrderFile, ios::trunc);
		ofs.close();
		cout << "预约信息已清空" << endl;
	}
	else
	{
		return;
	}
	return;
}
//初始化容器
void Manager::InitVector()
{
	ifstream ifs;
	ifs.open(StudentFile, ios::in);

	if (!ifs.is_open())
	{
		cout << "学生文件打开失败" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();
	Student s;
	while (ifs >> s.Snum && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	//cout << "当前学生个数为：" << vStu.size() << endl;
	ifs.close();
	ifs.open(TeacherFile, ios::in);
	Teacher t;
	if (!ifs.is_open())
	{
		cout << "老师文件打开失败" << endl;
		return;
	}
	while (ifs >> t.Tnum && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	/*cout << "当前老师个数为：" << vTea.size() << endl;*/
	ifs.close();
}

//检测添加id是否重复
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
