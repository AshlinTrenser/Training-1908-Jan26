#include "SiteTrackerController.h"
void SiteTrackerController::controllerMenu()
{
	int choice = 1;
	while (choice != 3)
	{
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
			return;
		}
	}
}
void SiteTrackerController::addUser()
{
	cout << "Name: ";
	cin.ignore();
	getline(cin, m_name);
	cout << "Phone: ";
	cin >> m_phone;
	cout << "Email: ";
	cin >> m_username;
	cout << "Enter Password: ";
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
	cout << "\nEmail: ";
	cin >> m_username;
	cout << "Password: ";
	cin >> m_password;
	for (auto iterator = m_user.begin(); iterator != m_user.end(); iterator++)
	{
		if ((*iterator)->getUsername() == m_username && ((*iterator)->getPassword() == m_password))
		{
			string type=(*iterator)->menu();
			if (type == "Owner")
			{
				ownerMenu((*iterator)->getName());
			}
			if (type == "Admin")
			{
				adminMenu((*iterator)->getName());
			}
		}
	}

}
void SiteTrackerController::adminMenu(string name)
{
	cout << "\nHai " << name<<endl;
	int choice = 1;
	while (choice != 7)
	{
		cout << "\n1.Add new Site\n2.Add Engineer\n3.View Site\n4.View Status\n5.View Site Request\n6.Assign Engineer to Site\n7.exit";
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
			//addEngineer();
			break;
		case 5:
			//viewSite();
			break;
		case 6:
			assignEngineerToSite();
			break;
		}
	}
}
void SiteTrackerController::viewSite()
{
	vector<Site*> sites = m_admin.getSite();
	if (sites.empty())
	{
		cout << "\nNo sites!\n";
		return;
	}
	int temp = 0;
	cout << "\n---Sites List----\n";
	for (auto site : sites)
	{
		cout << "Site " << temp + 1 << " details: \n";
		cout << "\nSite ID: " << site->getId();
		cout << "\nLocation: " << site->getLocation();
		cout << "\nArea of Square feet: " << site->getArea();
		cout << "\nOwner Name: " << site->getOwner();
		cout << "\nEngineer: " << site->getEngineer();
		cout << endl;
	}
}
void SiteTrackerController::assignEngineerToSite()
{
	cout << "\nEnter the Site ID: ";
	cin >> m_siteId;
	cout << "Enter the Engineer ID: ";
	cin >> m_engineerID;
	cout << endl;
	m_admin.assignEngineer(m_siteId, m_engineerID);
}
void SiteTrackerController::addSite()
{
	cout << "Site Id: ";
	cin >> m_id;
	cout << "\nLocation: ";
	cin >> m_location;
	cout << "Area of Square feet: ";
	cin >> m_area;
	cout << "Owner Name: ";
	cin >> m_owner;
	cout << "Phase: ";
	cin >> m_phase;
	m_admin.addNewSite(m_id,m_location, m_area, m_owner,m_phase);
}
void SiteTrackerController::addEngineer()
{
	cout << "Name: ";
	cin >> m_name;
	cout << "ID: ";
	cin >> m_id;
	cout << "Email: ";
	cin >> m_username;
	cout << "Password: ";
	cin >> m_password;
	cout << "Phone: ";
	cin >> m_phone;
	m_admin.addEngineer(m_name, m_phone, m_id, m_username, m_password);
}
void SiteTrackerController::ownerMenu(string name)
{
	cout << "\nHai " << name << endl;
}