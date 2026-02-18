#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include "User.h"
#include "Admin.h"
#include "Owner.h"
class SiteTrackerController
{
private:
	vector<User*> m_user;
public:
	void controllerMenu();
	void addUser();
	void loginUser();
};

