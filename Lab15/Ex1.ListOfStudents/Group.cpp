#include <Windows.h>
#include "Group.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Group::Group(string name)
{
	this->name = name;
}
Group::Group()
{
	name = "Без названия";
}
void Group::setName(string newName)
{
	name = newName;
}

string Group::getName()
{
	return name;
}

int Group::getSize()
{
	return (int)masSt.size();
}
void Group::addStudent(Student newStudent)
{
	masSt.push_back(newStudent);
}
void Group::delStudent(Student oldStudent)
{
	masSt.remove(oldStudent);
}
void Group::GroupOut()
{
	iter = masSt.begin();
	while (iter != masSt.end())
		(*iter++).display();
}

Student Group::findStudent(string searchName, string
	searchLastName)
{
	Student temp(searchName, searchLastName);
	iter = find(masSt.begin(), masSt.end(), temp);
	return(*iter);
}

void Group::GroupSort()
{
	masSt.sort();
}