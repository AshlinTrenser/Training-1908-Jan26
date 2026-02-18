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
void Admin::viewSite()
{

}
void Admin::addEngineer(string name, string phone, string id, string username, string password)
{
	m_engineers.push_back(new Engineer(name, phone, id, username, password));
}
void Admin::assignEngineer(string siteId, string engineerId)
{
	/*for (auto engineer : m_engineers)
	{
		if (engineer.getId() == engineerId)
		{
			engineer.setSiteId(siteId);
			assignSite.setEngineer(engineer.getName());
			cout << "\nEngineer " << engineer.getName() << " has been assigned to site " << siteId;
			return;
		}
	}*/
	cout << "\nEngineer not found!\n";
}