#pragma once
#include<iostream>
#include<string>
using namespace std;
class Task
{
private:
	string m_id, m_description, m_deadline, m_status;
	static int m_counter;
public:
	Task(string description, string deadline, string status);
	string getId();
	string getDescription();
	string getDeadline();
	string getStatus();
	void updateStatus(string newStatus);
};

