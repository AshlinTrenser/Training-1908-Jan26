#include "Owner.h"
Owner::Owner(string name, string phone, string username, string password) :User(username, password, "Owner")
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
void Owner::menu()
{
	cout << "\nOwner Menu\n";
}