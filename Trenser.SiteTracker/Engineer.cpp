#include "Engineer.h"
Engineer::Engineer(string name, string phone, string id, string username, string password) : User(username,password,"Engineer",name)
{
	m_name = name;
	m_phone = phone;
	m_id = id;
}
string Engineer::getName()
{
	return m_name;
}
string Engineer::getPhone()
{
	return m_phone;
}
string Engineer::getId()
{
	return m_id;
}
string Engineer::menu()
{
	return "Engineer";
}
void Engineer::setSiteId(string id)
{
	m_siteId = id;
}
string Engineer::getSiteId()
{
	return m_siteId;
}
void Engineer::addWorker(string id, string name, string role, int age, string siteID)
{
	worker.push_back(new Worker(id, name, role, age, siteID));
}
vector<Worker*> Engineer::displayWorker()
{
	return worker;
}
void Engineer::addMetrial(string name, string id, string siteID, int quantity)
{
	m_material.push_back(new Material(name, id, siteID, quantity));
}
vector<Material*> Engineer::displayMatrial()
{
	return m_material;
}
void Engineer::addTask(string id, string description, string deadline, string status)
{
	m_task.push_back(new Task(id, description,deadline, status));
}
vector<Task*> Engineer::displayTask()
{
	return m_task;
}
void Engineer::addStatus(string id,string message,vector<Site*>& sites)
{
	for (auto site : sites)
	{
		if (site->getId() == id)
		{
			site->updateStatus(message);
			return;
		}
	}
}
string Engineer::viewStatus(string id, vector<Site*>& sites)
{
	for (auto site : sites)
	{
		if (site->getId() == id)
		{
			return site->getStatusMessage();
		}
	}
	return "No Status Found!";
}