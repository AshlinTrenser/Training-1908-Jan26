#include "FileManager.h"
void FileManager::loadUsers(vector<User*>& users)
{
    ifstream file("User.txt");
    if (!file) return;

    string type, name, phone, username, password;

    while (file >> type >> name >> phone >> username >> password)
    {
        if (type == "Admin")
            users.push_back(new Admin(name, phone, username, password));

        else if (type == "Owner")
            users.push_back(new Owner(name, phone, username, password));
    }
}
void FileManager::loadEngineers(vector<Engineer*>& engineers)
{
    ifstream file("Engineer.txt");
    if (!file) return;

    string name, phone, id, username, password;

    while (file >> name >> phone >> id >> username >> password)
    {
        engineers.push_back(new Engineer(name, phone, id, username, password));
    }
}
void FileManager::loadSites(vector<Site*>& sites)
{
    ifstream file("Site.txt");
    if (!file) return;

    string id, location, owner;
    float area;
    int phase;

    while (file >> id >> location >> area >> owner >> phase)
    {
        sites.push_back(new Site(id, location, area, owner, phase));
    }
}

