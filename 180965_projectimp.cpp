#include "Project.h"

Project::Project(char* name, int budget, int duration)
{

	this->name = name;
	this->budget = budget;
	this->duration = duration;
}

Project::Project(const Project& c)
{

	this->name = c.name;
	this->budget = c.budget;
	this->duration = c.duration;
}

ostream& operator<<(ostream& osObject, const Project&c)
{
	osObject << " PROJECT NAME=  " << c.name << endl << "BUDGET= " << c.budget << endl << "DURATION= " << c.duration << endl;
	return osObject;
}
const Project& Project::operator=(const Project& xyz)
{
	name = new char[strlen(xyz.name) + 1];
	int i = 0;
	for (i = 0; i < strlen(xyz.name); i++)
	{
		name[i] = xyz.name[i];
	}
	name[i] = NULL;
	budget = xyz.budget;
	duration = xyz.duration;

	return *this;
}

void Project::setBudget(int budget)
{
	this->budget = budget;
}

Project::~Project()
{
	delete[] name;
	name = nullptr;
}
bool Project::exists(Project const* xyz)const
{
	if (strlen(name) == strlen(xyz->name))
	{
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] != xyz->name[i])
			{
				return false;
			}
		}
		return true;
	}
	else
		return false;

}
