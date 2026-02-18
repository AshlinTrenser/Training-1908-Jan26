#include "Engineer.h"
Engineer::Engineer(string name, string phone, string id, string username, string password) : User(username,password,"Engineer",name)
{
	m_name = name;
	m_phone = phone;
	m_id = id;
	cout << "\nAdded !\n";
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
	cout << "id: " << m_id<<endl;
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