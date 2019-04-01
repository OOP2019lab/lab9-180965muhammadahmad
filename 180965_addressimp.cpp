#include "Address.h"
#include "Project.h"
#include "Employee.h"


Address::Address(char* house_Number, char* Street_Name, char * City, char* County)
{
	
	int x=0;
	this->house_Number = house_Number;
	x = strlen(Street_Name);
	this->street_Name = new char[x + 1];
	for (int i = 0; Street_Name[i] != NULL; i++)
	{
		this->street_Name[i] = Street_Name[i];
	}
	this->street_Name[x] = NULL;
	x = 0;
	x = strlen(City);
	this->city = new char[x + 1];
	for (int i = 0; City[i] != NULL; i++)
	{
		this->city[i] = City[i];
	}
	this->city[x] = NULL;
	x = strlen(County);
	this->country = new char[x + 1];
	for (int i = 0; County[i] != NULL; i++)
	{
		this->country[i] = County[i];
	}
	this->country[x] = NULL;

}

Address::Address(const Address &xyz)
{
	this->house_Number = new char[strlen(xyz.house_Number) + 1];
	for (int i = 0; xyz.house_Number[i] != NULL; i++)
	{
		this->house_Number[i] = xyz.house_Number[i];

	}
	this->house_Number[strlen(xyz.house_Number)] = NULL;
	this->street_Name = new char[strlen(xyz.street_Name) + 1];
	for (int i = 0; xyz.house_Number[i] != NULL; i++)
	{
		this->street_Name[i] = xyz.street_Name[i];

	}
	this->street_Name[strlen(xyz.street_Name)] = NULL;
	this->city = new char[strlen(xyz.city) + 1];
	for (int i = 0; xyz.city[i] != NULL; i++)
	{
		this->city[i] = xyz.city[i];

	}
	this->city[strlen(xyz.city)] = NULL;
	this->country = new char[strlen(xyz.country) + 1];
	for (int i = 0; xyz.country[i] != NULL; i++)
	{
		this->country[i] = xyz.country[i];

	}
	this->country[strlen(xyz.country)] = NULL;



}

ostream& operator<<(ostream& osObject, const Address&c)
{
	osObject <<"HOUSE #= "<< c.house_Number <<endl<< "STREET NAME= " << c.street_Name <<endl<< "CITY= " << c.city <<endl<< "COUNTRY= " << c.country<<endl;
	return osObject;
}

const Address& Address::operator=(const Address& xyz)
{
	house_Number = new char[strlen(xyz.house_Number) + 1];
	int i = 0;
	for (i = 0; i < strlen(xyz.house_Number); i++)
	{
		house_Number[i] = xyz.house_Number[i];
	}
	house_Number[i] = NULL;
	street_Name = new char[strlen(xyz.street_Name) + 1];
	for (i = 0; i < strlen(xyz.street_Name); i++)
	{
		street_Name[i] = xyz.street_Name[i];
	}
	street_Name[i] = NULL;
	city = new char[strlen(xyz.city) + 1];
	for (i = 0; i < strlen(xyz.city); i++)
	{
		city[i] = xyz.city[i];
	}
	city[i] = NULL;
	country = new char[strlen(xyz.country) + 1];
	for (i = 0; i < strlen(xyz.country); i++)
	{
		country[i] = xyz.country[i];
	}
	country[i] = NULL;
	return *this;
}
Address::~Address()
{
	delete[] house_Number;
	house_Number = nullptr;
	delete[]street_Name;
	street_Name = nullptr;
	delete[]city;
	city = nullptr;
	delete[]country;
	country = nullptr;
}