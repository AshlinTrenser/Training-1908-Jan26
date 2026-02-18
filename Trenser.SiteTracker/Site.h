#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Site
{
private:
	string m_owner,m_location,m_engineer, m_id;
	float m_area;
	int m_phase;
public:
	Site() :m_id{}, m_owner{}, m_location{}, m_engineer{}, m_area{}, m_phase{} {}
	Site(string id, string location, float area, string owner,int phase);
	void setEngineer(string name);
	string getOwner();
	string getLocation();
	string getEngineer();
	string getId();
	float getArea();
	int getPhase();
};