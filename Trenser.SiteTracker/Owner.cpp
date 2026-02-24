#include "Owner.h"
Owner::Owner(string name, string phone, string username, string password) :User(username, password, "Owner", name, phone,true)
{
	m_name = name;
	m_phone = phone;/*
	m_isActive = true; */
}
Owner::Owner(string name, string phone, string username, string password,bool status) :User(username, password, "Owner",name,phone,status)
{
	m_name = name;
	m_phone = phone;
	/*if (status)
	{
		m_isActive = true;
	}
	else
	{
		m_isActive = false;
	}*/
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
//bool Owner::isActive()
//{
//	return m_isActive;
//}
//void Owner::deactive()
//{
//	m_isActive = false;
//}