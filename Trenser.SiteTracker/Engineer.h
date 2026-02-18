#pragma once
#include<iostream>
using namespace std;
#include "User.h"
class Engineer: public User
{
private:
	string m_name;
	string m_phone,m_id;
	string m_siteId;
public:
	Engineer() {}
	Engineer(string name, string phone, string id, string username, string password);
	string getUserName();
	string getPassword();
	string getName();
	string getPhone();
	string getId();
	string menu() override;
	void setSiteId(string id);
};

