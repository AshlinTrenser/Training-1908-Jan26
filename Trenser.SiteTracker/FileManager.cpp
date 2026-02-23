#include "FileManager.h"

void FileManager::loadUser(vector<User*>& users, Admin& admin) 
{
	ifstream file("User.txt");
	if (!file) {
		return;
	}

	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string m_name, m_phone, m_username, m_password, m_role, m_siteIds;

		getline(ss, m_name, '|');
		getline(ss, m_phone, '|');
		getline(ss, m_username, '|');
		getline(ss, m_password, '|');
		getline(ss, m_role, '|');

		if (m_role == "Admin")
		{
			users.push_back(new Admin(m_name, m_phone, m_username, m_password));
			cout << m_name << "\n";
		}
		else if (m_role == "Engineer")
		{
			getline(ss, m_siteIds, '|'); // only read site IDs for engineers
			vector<string> ids;
			string currentId;
			stringstream idStream(m_siteIds);
			while (getline(idStream, currentId, ','))
			{
				if (!currentId.empty()) {
					ids.push_back(currentId);
				}
			}
			users.push_back(admin.createEngineer(m_name, m_phone, m_username, m_password, ids));
		}
		else if (m_role == "Owner")
		{
			users.push_back(new Owner(m_name, m_phone, m_username, m_password));
		}
	}

	file.close();
}

void FileManager::saveUser(vector<User*> users)
{
	ofstream file(USER);
	for (auto user : users)
	{
		string m_role = user->getUserType();
		auto admin = dynamic_cast<Admin*>(user);
		file << user->getName() << "|";
		if (m_role == "Admin")
		{
			auto admin = dynamic_cast<Admin*>(user);
			file << admin->getPhone() << "|";
		}
		else if (m_role == "Engineer")
		{
			auto engineer = dynamic_cast<Engineer*>(user);
			file << engineer->getPhone() << "|";
		}
		else if (m_role == "Owner")
		{
			auto owner = dynamic_cast<Owner*>(user);
			file << owner->getPhone() << "|";
		}
		file << user->getUsername() << "|"
			<< user->getPassword() << "|"
			<< user->getUserType() << "|";
		if (m_role == "Engineer")
		{
			auto engineer = dynamic_cast<Engineer*>(user);
			for (const auto& id : engineer->getSiteId())
			{
				file << id << ",";
			}
		}
		file << "\n";
	}
	file.close();
}
void FileManager::loadSite(vector<Site*>& site)
{
	ifstream file(SITE);
	if (!file)
	{
		return;
	}
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		getline(ss, m_id, '|');
		getline(ss, m_SiteName, '|');
		getline(ss, m_owner, '|');
		getline(ss, m_location, '|');
		getline(ss, m_engineer, '|');
		getline(ss, m_area, '|');
		getline(ss, m_phase, '|');
		float area = stof(m_area);
		int phase = stoi(m_phase);
		site.push_back(new Site(m_SiteName,m_location, area, m_owner, phase,m_engineer));
	}
	file.close();
}

void FileManager::loadSiteStatus(vector<Status*>& siteStatus)
{
	ifstream file(SITESTATUS);
	if (!file)
	{
		return;
	}
	string line,m_message;
	while (getline(file, line))
	{
		stringstream ss(line);
		getline(ss, m_id, '|');
		getline(ss, m_message, '|');
		siteStatus.push_back(new Status(m_id, m_message));
	}
}
void FileManager::saveSite(vector<Site*>& sites)
{
	ofstream file(SITE);
	for (auto site : sites)
	{
		file << site->getId() << '|'
			<< site->getSiteName() << '|'
			<< site->getOwner() << '|'
			<< site->getLocation() << '|'
			<< site->getEngineer() << '|'
			<< site->getArea() << '|'
			<< site->getPhase() << '\n';
	}
	file.close();
}

void FileManager::saveSiteStatus(vector<Status*>& siteStatus)
{
	ofstream file(SITESTATUS);
	for (auto status : siteStatus)
	{
		file << status->getId() << '|' << status->getMessage() << '\n';
	}
	file.close();
}
