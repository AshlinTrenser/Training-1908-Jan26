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
public:
	Owner() {}
	Owner(string name, string phone, string username, string password);
	string getName();
	string getPhone();
	string menu() override;
	string getSiteId();
	vector<string> getSiteIds();
	void addSite(string id);
};

