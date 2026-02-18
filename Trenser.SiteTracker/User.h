#pragma once
#include<iostream>
#include<vector>
using namespace std;

class User
{
protected:
	string m_username;
	string m_password;
	string m_userType;
public:
	User() :m_username{}, m_password{}, m_userType{} {}
	User(string username, string password, string userType) :m_username{ username }, m_password{ password }, m_userType{userType} {}
	string getUsername();
	string getPassword();
	string getUserType();
	virtual void menu()=0;
};

