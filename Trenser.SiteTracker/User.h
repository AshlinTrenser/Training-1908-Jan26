#pragma once
#include<iostream>
#include<vector>
using namespace std;

class User
{
protected:
	string m_name,m_id;
	string m_username;
	string m_password;
	string m_userType;
public:
	User() :m_username{}, m_password{}, m_userType{}, m_name{} {}
	User(string username, string password, string userType, string name) 
		:m_username{ username }, m_password{ password }, m_userType{ userType }, m_name{ name } {}
	string getUsername();
	string getPassword();
	string getName();
	string getUserType();
	virtual string menu()= 0;
};

