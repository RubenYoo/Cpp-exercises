#pragma once
class Family
{
private:
	int familyNum;
	char name[20];
	int memberNum;
	int telephone;
	bool activities[6];
public:
	Family() : familyNum(0), name("\0"), memberNum(0), telephone(0)  { for (int i = 0; i < 6; i++) activities[i] = false; }
	Family(int, char str[20], int, int);

	void setFamilyNum(int);
	void setName(char str[20]);
	void setMemberNum(int);
	void setTelephone(int);
	void setActivities(bool, int);

	int getFamilyNum() const;
	char* getName();
	int getMemberNum() const;
	int getTelephone() const;
	bool getActivities(int) const;
};

