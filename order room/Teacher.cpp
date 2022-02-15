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
			// 1.查看所有预约
			/*cout << "1" << endl;*/
			ter->showAllOrder();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			// 2.审核预约
			/*cout << "2" << endl;*/
			ter->validOrder();
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

//无参构造
Teacher::Teacher()
{

}
//有参构造
Teacher::Teacher(int Tnum, string name, string pwd)
{
	this->Tnum = Tnum;
	this->m_name = name;
	this->m_pwd = pwd;
}

//老师菜单
void Teacher::operMenu()
{
	cout << "欢迎老师" << this->m_name << "登录!" << endl;
	cout << "\t\t-------------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                1.查看所有预约                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                2.审核预约                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                0.注销登录                           |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t-------------------------------------------------------\n";
	cout << "请输入您的选择：" << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	Order o;
	if (o.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < o.m_Size; i++)
	{
		cout << "预约学生姓名：" << o.m_OrderData[i]["name"] << "   ";
		cout << "预约日期： 周" << o.m_OrderData[i]["data"] << "   ";
		cout << "预约时段：" << (o.m_OrderData[i]["time"] == "1" ? "上午" : "下午") << "   ";
		cout << "预约机房编号：" << o.m_OrderData[i]["room"] << "   ";
		cout << "预约";
		string status = "状态：";
		if (o.m_OrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (o.m_OrderData[i]["status"] == "2")
		{
			status += "已预约";
		}
		if (o.m_OrderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		if (o.m_OrderData[i]["status"] == "0")
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
}

//审核预约
void Teacher::validOrder()
{
	Order o;
	if (o.m_Size == 0)
	{
		cout << "无需要审核记录" << endl;
		return;
	}
	else
	{
		vector<int> v;
		int index=0;
		cout << "您有如下记录需要审核：" << endl;
		for (int i = 0; i < o.m_Size; i++)
		{
			if (o.m_OrderData[i]["status"] == "1")
			{
				v.push_back(i);
				cout << ++index << "、";
				cout << "姓名：" << o.m_OrderData[i]["name"] << "   ";
				cout << "预约日期： 周" << o.m_OrderData[i]["data"] << "   ";
				cout << "预约时段：" << (o.m_OrderData[i]["time"] == "1" ? "上午" : "下午") << "   ";
				cout << "预约机房编号：" << o.m_OrderData[i]["room"] << endl;
			}
		}
		cout << "请输入审核的预约记录编号，0代表返回" << endl;
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
					cout << "请输入审核结果" << endl;
					cout << "1.通过" << endl;
					cout << "2.不通过" << endl;
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
					cout << "审核已完成" << endl;
					o.UpdataOrder();
					break;
				}
		    }
			else
			{
				cout << "请重新输入：" << endl;
			}
		}
		
	}
}