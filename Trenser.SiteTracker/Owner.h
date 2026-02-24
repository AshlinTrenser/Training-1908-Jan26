//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
using namespace std;
#include "User.h"
class Owner:
	public User
{
private:
	vector<string> m_siteIds;
	string m_name;
	string m_phone;
	//bool m_isActive;
public:
	Owner() = default;
	Owner(string name, string phone, string username, string password);
	Owner(string name, string phone, string username, string password,bool status);
	string getName();
	string getPhone();
	string menu() override;
	string getSiteId();
	vector<string> getSiteIds();
	void addSite(string id);
	/*void deactive();
	bool isActive();*/
};

