#include "Admin.h"
Admin::Admin(string name, string phone, string username, string password) : User(username, password, "Admin")
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
void Admin::menu()
{
	cout << "\nAdmin menu\n";
}