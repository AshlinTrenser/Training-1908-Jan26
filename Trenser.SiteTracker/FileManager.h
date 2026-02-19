#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Admin.h"
#include "Engineer.h"
#include "Owner.h"
#include "Site.h"
#include "Worker.h"
#include "Material.h"
#include "Task.h"

class FileManager
{
public:
    static void loadUsers(vector<User*>& users);
    static void loadSites(vector<Site*>& sites);
    static void loadEngineers(vector<Engineer*>& engineers);
};

