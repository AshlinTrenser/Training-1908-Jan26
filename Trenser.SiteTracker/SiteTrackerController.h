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
	Engineer m_engineerPurpose;
	vector<User*> m_user;
	vector<Engineer*> m_engineers;
	Admin m_admin;
	string m_name, m_username, m_password, m_repassword, m_phone,m_role,m_description,m_deadline,m_status,m_message;
	string m_location,m_owner,m_engineer,m_id,m_engineerID,m_siteId;
	float m_area;
	int m_type,m_phase, m_age,m_quantity;
public:
	void controllerMenu();
	void addUser();
	void loginUser();
	void adminMenu(string name);
	void ownerMenu(string name);
	void engineerMenu(string name);
	void addSite();
	void addEngineer();
	void viewSite();
	void assignEngineerToSite();
	void viewEngnieers();
	//void viewSiteRequest();
	void viewWorkers();
	void addWorkers();
	void addMaterial();
	void viewMaterials();
	void addTask();
	void viewTask();
	void addStatus();
	void viewStatus();
	void updateSitePhase();
	void updateTaskStatus();
};

