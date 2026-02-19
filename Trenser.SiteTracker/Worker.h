#pragma once
#include<iostream>
using namespace std;
class Worker
{
private:
	string m_workerName, m_role;
	string m_id, m_siteId;
	int m_age;
public:
	Worker(string id, string name, string role, int age, string siteId) 
		:m_id{ id }, m_workerName{ name }, m_role{ role }, m_age{ age }, m_siteId{ siteId } {}
	string getName();
	string getRole();
	string getId();
	string getSiteID();
	int getAge();
};

