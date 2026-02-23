//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#include<iostream>
using namespace std;
#include "FileManager.h"
#include "SiteTrackerController.h"
int main()
{
	FileManager fileManager;
	SiteTrackerController siteControl(&fileManager);
	siteControl.loadFromFiles();
	siteControl.controllerMenu();
	siteControl.saveToFile();
	return 0;
}