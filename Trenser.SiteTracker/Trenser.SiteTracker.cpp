#include<iostream>
using namespace std;
//#include "FileManager.h"
#include "SiteTrackerController.h"
int main()
{
	SiteTrackerController siteControl;/*
	FileManager::loadUsers(siteControl.getUsers());
	FileManager::loadSites(siteControl.getAdmin().getSite());
	FileManager::loadEngineers(siteControl.getAdmin().getEngineersList());*/
	siteControl.controllerMenu();
}