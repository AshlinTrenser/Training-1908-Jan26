#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include "User.h"
#include "Admin.h"
#include "Owner.h"
#include "Engineer.h"
class SiteTrackerController
{
private:
	vector<User*> m_user;
	Admin m_admin;
	string m_name, m_username, m_password, m_repassword, m_phone;
	string m_location,m_owner,m_engineer,m_id,m_engineerID,m_siteId;
	float m_area;
	int m_type,m_phase;
public:
	void controllerMenu();
	void addUser();
	void loginUser();
	void adminMenu(string name);
	void ownerMenu(string name);
	void addSite();
	void addEngineer();
	void viewSite();
	void assignEngineerToSite();
	void viewStatus();
	void viewSiteRequest();
};

