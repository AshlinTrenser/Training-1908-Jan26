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
void Admin::addNewSite(string id, string location, float area, string owner, int phase)
{
	m_site.push_back(new Site(id, location, area, owner, phase));
}
void Admin::addEngineer(string name, string phone, string id, string username, string password)
{
	m_engineers.push_back(new Engineer(name, phone, id, username, password));
}
string Admin::assignEngineer(string siteId, string engineerId)
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
	foundEngineer->setSiteId(siteId);
	foundSite->setEngineer(foundEngineer->getName());
	return "Engineer assigned successfully";
}
vector<Site*> Admin::getSite()
{
	return m_site;
}