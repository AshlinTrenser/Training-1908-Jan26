#pragma once
#include<iostream>
using namespace std;
class Worker
{
private:
	string m_workerName, m_role;
	int m_id, m_siteId, m_age;
public:
	Worker(int id, string name, string role, int age, int siteId) :m_id{ id }, m_workerName{ name }, m_role{ role }, m_age{ age }, m_siteId{ siteId } {}
};

