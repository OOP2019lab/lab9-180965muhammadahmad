#include "Employee.h"

Employee::Employee(char* name, const Address& address) :emp_name(name), employ_address(address)
{
	size_projects = 0;
	projects= new Project*[2];
}

Employee::Employee(const Employee&c) :emp_name(c.emp_name), employ_address(c.employ_address)
{
	size_projects = 0;
	projects= new Project*[2];
}

ostream& operator<<(ostream& osObject, const Employee&c)
{
	osObject << "The employee name is: " << c.emp_name << endl << "The address is: " << c.employ_address << endl << "PROJECTS:" << endl;
	for (int i = 0; i < c.size_projects; i++)
	{
		cout << *c.projects[i] << endl;
	}
	return osObject;
}

void Employee::addProject(Project const *project)
{
	if (size_projects >= 2)
		cout << "sorry we cant add it "<<endl;
	else
	{
		projects[size_projects] = new Project(*project);
		size_projects=size_projects+1;
	}
}

void Employee::removeProject(Project const * xyz)
{
	cout << "INVOKED" << endl;
	for (int i = 0; i<size_projects; i++)
	{
		if (projects[i]->exists(xyz)) 
		{
			for (int j = i; j<size_projects - 1; j++)
			{
				projects[j] = projects[j + 1];
			}
		}
	}
}

Employee::~Employee()
{
	
	delete[] emp_name;
	delete projects[0];
	delete projects[1];

}