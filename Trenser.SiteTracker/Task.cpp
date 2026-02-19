#include "Task.h"
string getId();
string getDescription();
string getDeadline();
string getStatus();

string Task::getId()
{
	return m_id;
}
string Task::getDescription()
{
	return m_description;
}
string Task::getDeadline()
{
	return m_deadline;
}
string Task::getStatus()
{
	return m_status;
}