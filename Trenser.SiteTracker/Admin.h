#pragma once
#include<iostream>
using namespace std;
#include "User.h"
class Admin:
	public User
{
private:
	string m_name;
	string m_phone;
public:
	Admin();
	Admin(string name, string phone, string username, string password);
	string getName();
	string getPhone();
	void menu() override;
};

