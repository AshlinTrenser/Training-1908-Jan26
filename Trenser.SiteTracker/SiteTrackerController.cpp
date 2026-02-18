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
	string name, username, password, repassword;
	string phone;
	int type;
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Phone: ";
	cin >> phone;
	cout << "Email: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;
	cout << "Re-Enter the Password: ";
	cin >> repassword;
	if (password != repassword)
	{
		system("cls");
		cout << "\nPassword mismatch! try again!\n";
		addUser();
		return;
	}
	cout << "\n1.Admin\n2.Owner\n";
	cout << "\nUser Type: ";
	cin >> type;
	if (type == 1)//admin
	{
		m_user.push_back(new Admin(name, phone, username, password));
	}
	if (type == 2)//Owner
	{
		m_user.push_back(new Owner(name, phone, username, password));
	}
}
void SiteTrackerController::loginUser()
{
	string username, password;
	cout << "\nUser Name: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	for (auto iterator = m_user.begin(); iterator != m_user.end(); iterator++)
	{
		if ((*iterator)->getUsername() == username && ((*iterator)->getPassword() == password))
		{
			(*iterator)->menu();
			return;
		}
	}
	cout << "\nInvailed email or password!\n";
}