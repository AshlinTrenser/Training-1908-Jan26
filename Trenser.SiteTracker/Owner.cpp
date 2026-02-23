#include "Owner.h"
Owner::Owner(string name, string phone, string username, string password) :User(username, password, "Owner",name)
{
	m_name = name;
	m_phone = phone;
}
string Owner::getName()
{
	return m_name;
}
string Owner::getPhone()
{
	return m_phone;
}
string Owner::menu()
{
	return "Owner";
}
vector<string> Owner::getSiteIds()
{
	return m_siteIds;
}

void Owner::addSite(string id)
{
	m_siteIds.push_back(id);
}