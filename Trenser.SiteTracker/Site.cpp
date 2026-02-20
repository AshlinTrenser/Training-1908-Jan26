#include "Site.h"
int Site::m_counter = 1;
Site::Site(string location, float area, string owner, int phase)
{
	if (m_counter < 10)
	{
		m_id = "S0" + to_string(m_counter);
	}
	else
	{
		m_id = "S" + to_string(m_counter);	
	}
	m_counter++;
	m_phase = phase;
	m_location = location;
	m_area = area;
	m_owner = owner;	
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
	if (m_engineer.empty())
	{
		return "Not assigned Engineer yet";
	}
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
void Site::updateStatus(string message)
{
	status.update(m_id, message);
}
string Site::getStatusMessage()
{
	return status.getMessage();
}
void Site::setPhase(int phase)
{
	m_phase = phase;
}