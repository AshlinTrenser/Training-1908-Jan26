#pragma once
#include<iostream>
using namespace std;
class Engineer
{
private:
	string m_name, m_username, m_passowrd;
	int m_phone,m_id;
public:
	Engineer(string name, int phone, int id, string username, string password) :m_name{ name }, m_phone{ phone }, m_id{id}, m_username { username }, m_passowrd{ password } {}
	string getUserName();
	string getPassword();
	string getName();
	int getPhone();
	int getId();
};

