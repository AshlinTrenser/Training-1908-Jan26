#pragma once
#include<iostream>
using namespace std;
#include "User.h"
class Owner:
	public User
{
private:
	string m_name;
	string m_phone;
public:
	Owner() {}
	Owner(string name, string phone, string username, string password);
	string getName();
	string getPhone();
	string menu() override;
};

