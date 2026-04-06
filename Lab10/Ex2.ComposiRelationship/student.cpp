/* student.cpp */
#include "student.h"
#include "IdCard.h"
#include <iostream>
#include <string>

using namespace std;


Student::Student(string name, string last_name, int id, string cat)
{
    set_name(name);
    set_last_name(last_name);
    setIdCard(id, cat);
    
    average_score = 0.0;
    for (int i = 0; i < 5; i++) scores[i] = 0;
}

void Student::setIdCard(int id, string c)
{
    iCard = IdCard(id, c);    
}

int Student::getIdCard()
{
    return iCard.getNumber(); // возвращает номер карты
}

void Student::display()
{
    cout << last_name << " " << name
        << "\t" << average_score
        << "\t" << iCard.getNumber()
        << "\t" << iCard.getCategory() << endl;
}


void Student::set_name(string student_name) { name = student_name; }

string Student::get_name() { return name; }

void Student::set_last_name(string student_last_name) { last_name = student_last_name; }

string Student::get_last_name() { return last_name; }

void Student::set_scores(int scores[]) {
    for (int i = 0; i < 5; ++i) this->scores[i] = scores[i];
}
void Student::set_average_score(double ball) { average_score = ball; }

double Student::get_average_score() { return average_score; }