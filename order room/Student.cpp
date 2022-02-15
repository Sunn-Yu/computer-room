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
			// 1.申请预约
			/*cout << "1" << endl;*/
			stu->applyOrder();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			// 2.查看我的预约
			/*cout << "2" << endl;*/
			stu->showMyOrder();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			/*cout << "3" << endl;*/
			// 3.查看所有预约
			stu->showAllOrder();
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			//4.取消预约
			/*cout << "4" << endl;*/
			stu->cancelOrder();
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
Student::Student()
{

}
//有参构造 学号 姓名 密码
Student::Student(int num, string name, string pwd)
{
	this->Snum = num;
	this->m_name = name;
	this->m_pwd = pwd;

	this->InitComputer();
}



//菜单界面
 void Student::operMenu()
{

	 cout << "欢迎学生" << this->m_name << "登录!" << endl;
	 cout << "\t\t-------------------------------------------------------\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                1.申请预约                           |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                2.查看我的预约                       |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                3.查看所有预约                       |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                4.取消预约                           |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t|                0.注销登录                           |\n";
	 cout << "\t\t|                                                     |\n";
	 cout << "\t\t-------------------------------------------------------\n";
	 cout << "请输入您的选择：" << endl;
}

//申请预约
 void Student::applyOrder()
 {
	 cout << "机房开放时间为周一至周五" << endl;
	 cout << "请选择申请预约时间" << endl;
	 cout << "1-周一" << endl;
	 cout << "2-周二" << endl;
	 cout << "3-周三" << endl;
	 cout << "4-周四" << endl;
	 cout << "5-周五" << endl;
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
			 cout << "输入有误，请重新输入：" << endl;
		 }
	 }
	 cout << "请选择申请预约的时间：" << endl;
	 cout << "1-上午" << endl;
	 cout << "2-下午" << endl;
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
			 cout << "请重新输入:" << endl;
		 }
	 }
	 cout << "请选择机房：" << endl;
	 cout << "一号机房容量为：" << vCom[0].m_MaxSize << endl;
	 cout << "二号机房容量为：" << vCom[1].m_MaxSize << endl;
	 cout << "三号机房容量为：" << vCom[2].m_MaxSize << endl;
	 cout << "1-1号机房" << endl;
	 cout << "2-2号机房" << endl;
	 cout << "3-3号机房" << endl;
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
			 cout << "您输入有误，请重新输入" << endl;
		 }
	 }

	 cout << "预约成功审核中" << endl;

	 ofstream ofs;
	 ofs.open(OrderFile, ios::app);
	 if (!ofs.is_open())
	 {
		 cout << "存储学生机房信息打不开文件！" << endl;
	 }
	 ofs << "name:" << this->m_name << " " << "data:" << data << " "
		 << "time:" << time << " " << "room:" << room << " "
		 << "sId:" << this->Snum << " " << "status:" << 1 << endl;
	 ofs.close();
 }

//查看我的预约
void Student::showMyOrder()
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
		if (atoi(o.m_OrderData[i]["sId"].c_str()) == this->Snum)
		{
			cout << "预约日期： 周" << o.m_OrderData[i]["data"]  << "   ";
			cout << "预约时段：" << (o.m_OrderData[i]["time"] == "1" ? "上午" : "下午" )<< "   ";
			cout << "预约机房编号：" << o.m_OrderData[i]["room"] << "   ";
			cout << "您的预约";
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

}

//查看所有预约
void Student::showAllOrder()
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
		cout << "预约学生姓名：" << o.m_OrderData[i]["name"] <<"   ";
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

//取消预约
void Student::cancelOrder()
{
	Order o;
	if (o.m_Size == 0)
	{
		cout << "无预约信息" << endl;
		return;
	}
	cout << "您有以下预约记录可以更改：" << endl;
	vector<int>v;
	int indx = 1;
	for (int i = 0; i < o.m_Size; i++)
	{
		if (this->Snum == atoi(o.m_OrderData[i]["sId"].c_str()))
		{
			if (o.m_OrderData[i]["status"] == "1" || o.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
			
				cout << indx++ << "、";
				cout << "预约日期： 周" << o.m_OrderData[i]["data"] <<"   ";
				cout << "预约时段：" << (o.m_OrderData[i]["time"] == "1" ? "上午" : "下午") << "   ";
				cout << "预约机房编号：" << o.m_OrderData[i]["room"] << "   ";
				string status = "预约状态：";
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
			else
			{
				cout << "您的预约无法取消" << endl;
			}
		}
		
	}
	cout << "请输入您需要取消的预约编号,0代表返回" << endl;
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
			cout << "已取消该预约" << endl;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	

}
//读取机房信息
void Student::InitComputer()
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