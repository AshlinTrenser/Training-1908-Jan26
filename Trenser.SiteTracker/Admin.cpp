#include "Admin.h"
Admin::Admin(string name, string phone, string username, string password) : User(username, password, "Admin",name)
{
	m_name = name;
	m_phone = phone;
}
string Admin::getName()
{
	return m_name;
}
string Admin::getPhone()
{
	return m_phone;
}
string Admin::menu()
{
	return "Admin";
}
void Admin::addNewSite(string siteName,string location, float area, string owner, int phase)
{
	m_site.push_back(new Site(siteName,location, area, owner, phase));
}
Engineer* Admin::createEngineer(string name, string phone, string username, string password)
{
	Engineer* engineer = new Engineer(name, phone, username, password);
	m_engineers.push_back(engineer);
	return engineer;
}
Engineer* Admin::createEngineer(string name, string phone, string username, string password,vector<string> ids)
{
	Engineer* engineer = new Engineer(name, phone, username, password,ids);
	m_engineers.push_back(engineer);
	return engineer;
}
string Admin::assignEngineerToSite(string siteId, string engineerId)
{
	Engineer* foundEngineer = nullptr;
	Site* foundSite = nullptr;
	for (auto engineer : m_engineers)
	{
		if (engineer->getId() == engineerId)
		{
			foundEngineer = engineer;
			break;
		}
	}
	for (auto site : m_site)
	{
		if (site->getId() == siteId)
		{
			foundSite = site;
			break;
		}
	}
	if (!foundEngineer || !foundSite)
	{
		return "ID is not in your Data Base, Try another one!";
	}
	foundEngineer->setSiteId(siteId);
	foundSite->setEngineer(foundEngineer->getName());
	return "Engineer assigned successfully";
}
vector<Site*>& Admin::getSite()
{
	return m_site;
}
vector<Task*>& Admin::getTask()
{
	return m_task;
}
vector<Engineer*> Admin::getEngineersList()
{
	return m_engineers;
}
string Admin::viewSiteStatus(string siteID)
{
	for (auto site : m_site)
	{
		if (site->getId() == siteID)
		{
			string message = site->getSiteStatusMessage();
			if (message.empty())
			{
				return "No Status Updates";
			}
			return message;
		}
	}
	return "Site Not Found";
}
bool Admin::deleteSite(string id)
{
	for (auto task = m_task.begin(); task != m_task.end();)
	{
		if ((*task)->getSiteID() == id)
		{
			delete* task;
			task = m_task.erase(task);
		}
		else { task++; }
	}
	for (auto iterator = m_site.begin(); iterator != m_site.end(); iterator++)
	{
		if ((*iterator)->getId() == id)
		{
			m_site.erase(iterator);
			return true;
		}
	}
	return false;
}
Admin::~Admin()
{
	for (auto site : m_site)
	{
		delete site;
	}
	for (auto engineer : m_engineers)
	{
		delete engineer;
	}
	for (auto task : m_task)
	{
		delete task;
	}
}