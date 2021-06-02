#pragma once
class GiveFromHeart
{
	//declaring the private variables of the class
private:
	int id;
	char name[21];
	float salaryPerHour;
	int hours;
	float inbound;
	//setting all the prototypes of the instances of the class
	//and also setting a constructor
public:
	GiveFromHeart();
	void setId(int num);
	int getId();
	void setName(char name[21]);
	char* getName();
	void setSalaryPerHour(float num);
	float getSalaryPerHour();
	void setHours(int num);
	int getHours();
	void setInbound(float num);
	float getInbound();
	float salary();
	void clear();
	bool validityCheck();
};

