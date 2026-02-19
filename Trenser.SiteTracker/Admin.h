#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include "User.h"
#include "Site.h"
#include "Status.h"
#include "Engineer.h"
class Admin:
	public User
{
private:
	string m_name;
	string m_phone;
	Site assignSite;
	vector<Site*> m_site;
	vector<Engineer*> m_engineers;
public:
	Admin() :m_name{}, m_phone{} {}
	Admin(string name, string phone, string username, string password);
	string getName();
	string getPhone();
	string menu() override;
	void addNewSite(string id, string location, float area, string owner, int phase);
	Engineer* createEngnieer(string name, string phone, string id, string username, string password);
	string assignEngineer(string siteId,string engineerId);
	vector<Engineer*> getEngineersList();
	vector<Site*>& getSite();
	string viewStatus(string siteID);
};

