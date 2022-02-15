#include"Order.h"
//构造函数
Order::Order()
{
	this->InitOrder();
}

//更新函数；
void Order::UpdataOrder()
{
	if (this->m_Size == 0)
	{
		return;
    }
	ofstream ofs;
	ofs.open(OrderFile, ios::out | ios::trunc);
   for (int i = 0; i < this->m_Size; i++)
   {
	   ofs << "name:" << this->m_OrderData[i]["name"] << " ";
	   ofs << "data:" << this->m_OrderData[i]["data"] << " "  ;
	   ofs << "time:" << this->m_OrderData[i]["time"] << " "  ;
	   ofs << "room:" << this->m_OrderData[i]["room"] << " "  ;
	   ofs << "sId:" << this->m_OrderData[i]["sId"] << " "  ;
       ofs << "status:" << this->m_OrderData[i]["status"] << endl;
   }
   ofs.close();
}
//初始化预约信息
void Order::InitOrder()
{
	ifstream ifs;
	ifs.open(OrderFile, ios::in);
	this->m_Size = 0;
	if (!ifs.is_open())
	{
		cout << "预约信息读取失败" << endl;
	}
	string name;
	string data;
	string time;
	string room;
	string sId;
	string status;
	string valu;
	string kay;
	map<string, string>info;
	while (ifs >> name && ifs >> data && ifs >> time && ifs >> room && ifs >> sId && ifs >> status)
	{
		info.clear();
		int pos = name.find(":");
		if (pos != -1)
		{
			kay = name.substr(0, pos);
			valu = name.substr(pos + 1, name.size());
			info.insert(make_pair(kay, valu));
		}
		
		

		 pos = data.find(":");
		if (pos != -1)
		{
			kay = data.substr(0, pos);
			valu = data.substr(pos + 1, data.size());
			info.insert(make_pair(kay, valu));
		}
	

		
		
		 pos = time.find(":");
		if (pos!=-1)
		{
			kay = time.substr(0, pos);
			valu = time.substr(pos + 1, time.size());
			info.insert(make_pair(kay, valu));

		}
		


		 pos = room.find(":");
		if (pos != -1)
		{
			kay = room.substr(0, pos);
			valu = room.substr(pos + 1, room.size());
			info.insert(make_pair(kay, valu));
		}




		 pos = sId.find(":");
		if (pos != -1)
		{
			kay = sId.substr(0, pos);
			valu = sId.substr(pos + 1, sId.size());
			info.insert(make_pair(kay, valu));
		}



		 pos = status.find(":");
		if (pos != -1)
		{
			kay = status.substr(0, pos);
			valu = status.substr(pos + 1, status.size());
			info.insert(make_pair(kay, valu));
		}
	

		this->m_OrderData.insert(make_pair(this->m_Size, info));
		this->m_Size++;
	}
	
		
	ifs.close();
	//for (map<int, map<string, string>>::iterator it = m_OrderData.begin(); it != m_OrderData.end(); it++)
	//{
	//	cout << "key=" << it->first << "valu=" << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
	//	{
	//		cout << "key=" << mit->first << "valu=" << mit->second << endl;
	//	}

	//}

}