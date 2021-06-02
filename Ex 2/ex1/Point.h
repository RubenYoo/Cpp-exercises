#pragma once
class Point
{
	//private variables of the class
private:
	int x;
	int y;
	//methods of the class
public:
	void setX(int myX);
	void setY(int myY);
	int getX() const;
	int getY() const;
	float distance(Point point2);
};
