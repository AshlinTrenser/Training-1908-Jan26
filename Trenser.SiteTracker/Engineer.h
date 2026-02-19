#pragma once
#include<iostream>
#include<map>
using namespace std;
#include "User.h"
#include "Material.h"
#include "Worker.h"
#include "Task.h"
#include "Status.h"
#include "Site.h"
class Engineer: public User
{
private:

	vector<Worker*> worker;
	vector<Material*> m_material;
	vector<Task*> m_task;
	string m_name;
	string m_phone,m_id;
	string m_siteId;
public:
	Engineer() {}
	Engineer(string name, string phone, string id, string username, string password);
	string getName();
	string getPhone();
	string getId();
	string getSiteId();
	string menu() override;
	void setSiteId(string id);
	void addWorker(string id, string name, string role, int age, string siteID);
	vector<Worker*> displayWorker();
	void addMetrial(string name, string m_id, string siteID, int quantity);
	vector<Material*> displayMatrial();
	void addTask(string id, string description, string deadline, string status);
	vector<Task*> displayTask();
	void addStatus(string id,string message,vector<Site*>& sites);
	string viewStatus(string id, vector<Site*>& sites);
};

