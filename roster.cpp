//
//  roster.cpp
//  C867
//
//  Created by Troy Cost on 9/29/22.
//


#include <string>
#include "roster.h"

void Roster::parse(string studentdata) //parses each row of data
{
    
    int rhs = studentdata.find(',');//find the comma, return index
    string ID = studentdata.substr(0, rhs);//extract substring in front of comma
    
    int lhs = rhs + 1;//move past previous comma
    rhs = studentdata.find(',', lhs);
    string FirstName = studentdata.substr(lhs, rhs - lhs);//First name
    
    lhs = rhs + 1;//continue
    rhs = studentdata.find(',', lhs);
    string LastName = studentdata.substr(lhs, rhs - lhs);//Last name
    
    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    string Email = studentdata.substr(lhs, rhs -lhs);
    
    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    int Age = stoi(studentdata.substr(lhs, rhs -lhs));
    
    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    int daysInCourse1 = stod(studentdata.substr(lhs, rhs-lhs));//first number of days
    
    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    int daysInCourse2 = stod(studentdata.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    int daysInCourse3 = stod(studentdata.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);

    DegreeType dt  = SECURITY;
    
    if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') dt = SECURITY;
    else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O') dt = SOFTWARE;
    else if (studentdata.at(lhs) == 'N') dt = NETWORK;
    
    add(ID, FirstName, LastName, Email, Age, daysInCourse1, daysInCourse2, daysInCourse3, dt);

}


void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType dt)
{
    //days back into an array
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    //make new book object; first index -1
    //be sure to use ++ prefix not postfix because starting at -1
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourse, dt);//use full constructor
}

//display all students
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::printInvalidEmails()
{
    bool any = false;
    //assume no ivalid emails
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getEmail());
        //create variable to shorten statement below
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
        {
            any = true;
            //any reassigned true if if-statement met
            cout << email << ":" << classRosterArray[i]->getFName() << std::endl;
            //prints invalid email
        }
    }
    if (!any) cout << "NONE" << std::endl;
    //prints if no invalid IDs
}


void Roster::printAverageDays(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID()==studentID)
        {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDays()[0]+
                     classRosterArray[i]->getDays()[1]+
                     classRosterArray[i]->getDays()[2])/3 << std::endl;
            //divide by number of course day counts
        }
    }
}

//display students matching degree type
void Roster::printByDegreeType(DegreeType dt)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeType() == dt) classRosterArray[i]->print();
    }
    cout << std::endl;
}

bool Roster::remove(string studentID)
//takes student id for student to be removed 
{
    bool success = false; //assume student does not exist
    for (int i=0; i <= Roster::lastIndex; i++)
    //use lastIndex since index may change
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            success = true;//found student
            if (i < studentData - 1)
            {
                Student* temp = classRosterArray[i];//swaps places with A5 - last student
                classRosterArray[i] = classRosterArray[studentData - 1];
                classRosterArray[studentData - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << studentID << " removed from roster." << std::endl << std::endl;
        this->printAll();//display all students except removed students
    }
    else cout << studentID << " not found." << std::endl << std::endl;;
    return 0;
}

Roster::~Roster()
{
cout << "Destructor called!" << std::endl << std::endl;
    for (int i=0; i < studentData; i++)
    //size of numBooks stays the same unlike lastIndex
    {
        cout << "Removing student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
 
