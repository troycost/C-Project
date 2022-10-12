//
//  roster.h
//  C867
//
//  Created by Troy Cost on 9/27/22.
//

#pragma once
#include "student.h"


class Roster
{
public:
    int lastIndex = -1;
    const static int studentData = 5;
    Student* classRosterArray[studentData];

    
public:
    void parse(string row);
    //pulls student data and creates student objects in roster
    void add(string ID,
             string FName,
             string LName,
             string Email,
             int Age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeType dt);

    void printAll();//calls print() for each student 
    void printByDegreeType(DegreeType dt);
    void printInvalidEmails();//a valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    void printAverageDays(string studentID);//prints average days used for each class
    bool remove(string studentID);//find student and remove student A3
    ~Roster();//destructor
};
