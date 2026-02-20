#include "SiteTrackerController.h"
void SiteTrackerController::controllerMenu()
{
	int choice = 1;
	while (choice != 3)
	{
		system("cls");
		cout << "Welcome to ABC construction site tracker...\n";
		cout << "\n1.Registration\n2.Login\n3.Exit\nEnter your choice: ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			addUser();
			break;
		case 2:
			loginUser();
			break;
		case 3:
			break;
		default:
			cout << "Invalid input! try again";
			break;
		}
	}
}
void SiteTrackerController::ownerMenu(string name)
{
	system("cls");
	cout << "\nSite Owner: " << name << endl;
	int choice = 1;
	while (choice != 3)
	{
		cout << "\n1.Send site Request to Admin\n2.View Status of Site\n3.Logout\n Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "\nLocation         : ";
			cin >> m_location;
			cout << "Area of Square feet: ";
			cin >> m_area;
			cout << "Site Owner Name    : ";
			cin.ignore();
			getline(cin, m_owner);
			m_admin.addNewSite(m_location, m_area, m_owner, 1);
			break;
		case 2:
			viewStatus();
			break;
		case 3:
			break;
		default:
			cout << "Invalid input! try again";
			break;
		}
	}
}
void SiteTrackerController::adminMenu(string name)
{
	system("cls");
	cout << "\nAdmin: " << name << endl;
	int choice = 1;
	while (choice != 10)
	{
		cout << "\n1.Add new Site\n2.Add Engineer\n3.View Site\n4.View Engineers\n5.View Site Status\n6.Assign Engineer to Site\n7.Add Task\n8.Delete Site\n9.View Task\n10.Logout\n Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addSite();
			break;
		case 2:
			addEngineer();
			break;
		case 3:
			viewSite();
			break;
		case 4:
			viewEngnieers();
			break;
		case 5:
			viewStatus();
			break;
		case 6:
			assignEngineerToSite();
			break;
		case 7:
			addTask();
			break;
		case 8:
			deleteSite();
			break;
		case 9:
			viewTask();
			break;
		case 10:
			break;
		default:
			cout << "Invalid input! try again";
			break;
		}
	}
}
void SiteTrackerController::engineerMenu(string name)
{
	system("cls");
	cout << "\nEngineer: " << name << endl;
	int choice = 1;
	while (choice != 11)
	{
		cout << "\n1.Add works\n2.Add Site status\n3.Add Materials\n4.Add Task\n5.View workers\n6.View site status\n7.View Materials\n8.View Task\n9.Update Site Phase\n10.Update Task Status\n11.Logout\nEnter you choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addWorkers();
			break;
		case 2:
			addStatus();
			break;
		case 3:
			addMaterial();
			break;
		case 4:
			addTask();
			break;
		case 5:
			viewWorkers();
			break;
		case 6:
			viewStatus();
			break;
		case 7:
			viewMaterials();
			break;
		case 8:
			viewTask();
			break;
		case 9:
			updateSitePhase();
			break;
		case 10:
			updateTaskStatus();
			break;
		default:
			cout << "Invalid input! try again";
			break;
		}
	}
}
void SiteTrackerController::addUser()
{
	system("cls");		
	cout << "Name                 : ";
	cin.ignore();
	getline(cin, m_name);
	cout << "Phone                : ";
	cin >> m_phone;
	cout << "Email                : ";
	cin >> m_username;
	cout << "Enter Password       : ";
	cin >> m_password;
	cout << "Re-Enter the Password: ";
	cin >> m_repassword;
	if (m_password != m_repassword)
	{
		system("cls");
		cout << "\nPassword mismatch! try again!\n";
		addUser();
		return;
	}
	cout << "\n1.Admin\n2.Owner\n\nUser Type: ";
	cin >> m_type;
	if (m_type == 1)
	{
		m_user.push_back(new Admin(m_name, m_phone, m_username, m_password));
	}
	if (m_type == 2)
	{
		m_user.push_back(new Owner(m_name, m_phone, m_username, m_password));
	}
}
void SiteTrackerController::loginUser()
{
	system("cls");
	cout << "\nEmail : ";
	cin >> m_username;
	cout << "Password: ";
	cin >> m_password;
	if (m_user.empty())
	{
		cout << "\nNo Users are registered. Please register\n";
		return;
	}
	for (auto iterator = m_user.begin(); iterator != m_user.end(); iterator++)
	{
		if ((*iterator)->getUsername() == m_username && ((*iterator)->getPassword() == m_password))
		{
			string type=(*iterator)->menu();
			if (type == "Owner")
			{
				ownerMenu((*iterator)->getName());
			}
			else if (type == "Admin")
			{
				adminMenu((*iterator)->getName());
			}
			else if (type == "Engineer")
			{
				engineerMenu((*iterator)->getName());
			}
			return;
		}
	}
}
void SiteTrackerController::updateTaskStatus()
{
	viewTask();
	cout << endl<<"\n Which Task you want to change!";
	cout << "\nEnter the Task ID: ";
	cin >> m_id;
	cout << "Status             : ";
	cin.ignore();
	getline(cin, m_status);
	string result = m_engineerPurpose.updateTaskStatus(m_id, m_status);
	cout << result << endl<<endl;
}
void SiteTrackerController::updateSitePhase()
{
	viewSite();
	cout << "Enter the Site ID: ";
	cin >> m_id;
	cout << "Phase            : ";
	cin >> m_phase;
	string result=m_engineerPurpose.updateSitePhase(m_id, m_phase,m_admin.getSite());
	cout <<endl<< result<<endl<<endl;
}
void SiteTrackerController::addStatus()
{
	system("cls");
	cout << "\nEnter the site ID: ";
	cin >> m_siteId;
	cout << "\nEnter the ReMark : ";
	cin.ignore();
	getline(cin, m_message);
	string result=m_engineerPurpose.addStatus(m_siteId,m_message,m_admin.getSite());
	cout << "\n" << result << "\n\n";
}
void SiteTrackerController::viewStatus()
{
	system("cls");
	cout << "\nEnter the site ID to view: ";
	cin >> m_siteId;
	m_message=m_engineerPurpose.viewStatus(m_siteId,m_admin.getSite());
	if (m_message.empty())
	{
		cout << "\nNo Updates!\n";
		return;
	}
	cout << endl << "Here is the status : " << m_message;
}
void SiteTrackerController::addTask()
{
	system("cls");
	cout << "Task Description: ";
	cin.ignore();
	getline(cin, m_description);
	cout << "Dead Line       : ";
	cin >> m_deadline;
	cout << "Status          : ";
	cin.ignore();
	getline(cin, m_status);
	cout << "Site ID: ";
	cin >> m_siteId;
	bool found = m_engineerPurpose.checkSiteID(m_siteId, m_admin.getSite());
	if (!found)
	{
		cout << "\nThe Site Id is NOT in your database!\n\n";
		return;
	}
	m_engineerPurpose.addTask( m_description, m_deadline, m_status,m_siteId);
}
void SiteTrackerController::viewTask()
{
	system("cls");
	cout << "\n---Task Details---\n";
	vector<Task*> task = m_engineerPurpose.displayTask();
	if (task.empty())
	{
		cout << "\nNo Task Added!";
		return;
	}
	for (auto details : task)
	{
		cout << "Task ID         : " << details->getId()<<endl;
		cout << "Task Description: " << details->getDescription()<<endl;
		cout << "Task dead line  : " << details->getDeadline()<<endl;
		cout << "Task status     : " << details->getStatus() << endl;
		cout << "Site Id         :" << details->getSiteID() << endl << endl;
	}
}
void SiteTrackerController::addMaterial()
{
	system("cls");
	cout << "\n Materials Name: ";
	cin >> m_name;
	cout << "Site ID          : ";
	cin >> m_siteId;
	bool found = m_engineerPurpose.checkSiteID(m_siteId, m_admin.getSite());
	if (!found)
	{
		cout << "\nThe Site Id is NOT in your database!\n\n";
		return;
	}
	cout << "Quantity         : ";
	cin >> m_quantity;
	m_engineerPurpose.addMetrial(m_name, m_siteId, m_quantity);
}
void  SiteTrackerController::viewMaterials()
{
	system("cls");
	cout << "\n---Materials Details---\n";
	vector<Material*> material = m_engineerPurpose.displayMatrial();
	if (material.empty())
	{
		cout << "\nNo Materials Are Added!";
		return;
	}
	for (auto details : material)
	{
		cout << "\nMaterial Name: " << details->getName();
		cout << "\nMaterial ID  : " << details->getId();
		cout << "\nSite ID      : " << details->getSiteID();
		cout << "\nQuantity     : " << details->getQuantity() << endl;
	}
}
void SiteTrackerController::viewWorkers()
{
	system("cls");
	cout << "\n---Worker Details---\n";
	vector<Worker*> worker = m_engineerPurpose.displayWorker();
	if (worker.empty())
	{
		cout << "\nNo Workers Added\n";
		return;
	}
	for (auto user : worker)
	{
		cout << "\nName   : " << user->getName();
		cout << "\nRole   : " << user->getRole();
		cout << "\nID     : " << user->getId();
		cout << "\nSite ID: " << user->getSiteID();
		cout << "\nAge    : " << user->getAge()<<endl;
	}
}
void SiteTrackerController::addWorkers()
{
	system("cls");
	cout << "Worker Name : ";
	cin.ignore();
	getline(cin, m_name);
	cout << "Worker Role : ";
	cin >> m_role;
	cout << "Worker Age  : ";
	cin >> m_age;
	cout << "Site ID     : ";
	cin >> m_siteId;
	m_engineerPurpose.addWorker(m_name, m_role, m_age, m_siteId);
}
void SiteTrackerController::viewEngnieers()
{
	system("cls");
	vector<Engineer*> engineerList=m_admin.getEngineersList();
	if (engineerList.empty())
	{
		cout << "\n---No engineers---\n";
		return;
	}
	cout << "\n---Engineer List---\n";
	for (auto user : engineerList)
	{
		cout << "Engineer ID              : " << user->getId()<<endl;
		cout << "Engineer Name            : " << user->getName()<<endl;
		cout << "Engineer Phone           : " << user->getPhone()<<endl;
		cout << "Engineer Assigned Site ID: " << user->getSiteId()<<endl << endl << endl;;
	}
}
void SiteTrackerController::viewSite()
{
	system("cls");
	vector<Site*> sites = m_admin.getSite();
	if (sites.empty())
	{
		cout << "\nNo sites!\n";
		return;
	}
	cout << "\n---Sites List----\n";
	for (auto site : sites)
	{
		cout << "\nSite ID            : " << site->getId();
		cout << "\nLocation           : " << site->getLocation();
		cout << "\nArea of Square feet: " << site->getArea();
		cout << "\nOwner Name         : " << site->getOwner();
		cout << "\nSite Phase         : " << site->getPhase();
		cout << "\nEngineer           : " << site->getEngineer() << endl << endl<<endl;
	}
}
void SiteTrackerController::assignEngineerToSite()
{
	system("cls");
	cout << "\nEnter the Site ID  : ";
	cin >> m_siteId;
	cout << "Enter the Engineer ID: ";
	cin >> m_engineerID;
	cout << endl;
	string result= m_admin.assignEngineer(m_siteId, m_engineerID);
	cout << result<<endl<<endl;
}
void SiteTrackerController::addSite()
{
	system("cls");
	cout << "Location           : ";
	cin >> m_location;
	cout << "Area of Square feet: ";
	cin >> m_area;
	cout << "Owner Name         : ";
	cin.ignore();
	getline(cin,m_owner);
	cout << "Phase              : ";
	cin >> m_phase;
	m_admin.addNewSite(m_location, m_area, m_owner,m_phase);
}
void SiteTrackerController::addEngineer()
{
	system("cls");
	cout << "Name    : ";
	cin.ignore();
	getline(cin, m_name);
	cout << "Email   : ";
	cin >> m_username;
	cout << "Password: ";
	cin >> m_password;
	cout << "Phone   : ";
	cin >> m_phone;
	Engineer* engineer = m_admin.createEngnieer(m_name, m_phone, m_username, m_password);
	m_user.push_back(engineer);
}
void SiteTrackerController::deleteSite()
{
	system("cls");
	cout << "\nEnter the site ID to delete: ";
	cin >> m_id;
	bool isDeleted = m_admin.deleteSite(m_id);
	if (isDeleted)
	{
		cout << "\n\n\Deleted Successfully!\n\n";
	}
}