//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
using namespace std;
class Status
{
private:
	string m_siteID,m_message;
public:
	Status() :m_siteID{}, m_message{} {}
	void update(string id, string message);
	string getId();
	string getMessage();
};

