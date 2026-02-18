#include "Site.h"
Site::Site(string id, string location, float area, string owner, int phase)
{
	m_phase = phase;
	m_id = id;
	m_location = location;
	m_area = area;
	m_owner = owner;
	cout << "\nSite added\n";
}
void Site::setEngineer(string name)
{
	m_engineer = name;
}
string Site::getOwner()
{
	return m_owner;
}
string Site::getLocation()
{
	return m_location;
}
string Site::getEngineer()
{
	return m_engineer;
}
string Site::getId()
{
	return m_id;
}
float Site::getArea()
{
	return m_area;
}
int Site::getPhase()
{
	return m_phase;
}