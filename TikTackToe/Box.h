#pragma once
#include <iostream>
#include <string>
using namespace std;


class box
{
public:
	box()
	{
		name = "-";
	}

	box(string& Name)
	{
		name = Name;
	}
	virtual char Draw() = 0;
	virtual string GetName()
	{
		return name;
	}

private:
	string name;
};

class Cross :
	public box
{
public:
	Cross(string& Name) : box(Name)
	{

	}
	virtual char Draw()
	{
		return 'X';
	}
	virtual string GetName()
	{
		return box::GetName() + "!";
	}
};
class Circle :
	public box
{
public:
	Circle(string& Name) : box(Name)
	{

	}
	virtual char Draw()
	{
		return 'O';
	}
	virtual string GetName()
	{
		return box::GetName() + "!";
	}
};
class Empty :
	public box
{
public:
	virtual char Draw()
	{
		return '*';
	}

	int p;
};