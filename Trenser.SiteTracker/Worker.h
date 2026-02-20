#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker
{
private:
	static int m_counter;
	string m_workerName, m_role;
	string m_id, m_siteId;
	int m_age;
public:
	Worker(string name, string role, int age, string siteId);
	string getName();
	string getRole();
	string getId();
	string getSiteID();
	int getAge();
};

