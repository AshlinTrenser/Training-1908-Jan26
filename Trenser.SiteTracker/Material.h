#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Material
{
private:
	string m_name,m_id,m_siteId;
	int m_quantity;
public:
	Material(string name, string id, string siteID, int quantity)
		:m_name{ name }, m_id{ id }, m_siteId{ siteID }, m_quantity{ quantity } {}
	string getName();
	string getId();
	string getSiteID();
	int getQuantity();
};

