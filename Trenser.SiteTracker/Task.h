#pragma once
#include<iostream>
using namespace std;
class Task
{
private:
	string m_id, m_description, m_deadline, m_status;
public:
	Task(string id, string description, string deadline, string status)
		:m_id{ id }, m_description{ description }, m_deadline{ deadline }, m_status{ status } {}
	string getId();
	string getDescription();
	string getDeadline();
	string getStatus();
};

