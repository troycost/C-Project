//
//  student.h
//  C867
//
//  Created by Troy Cost on 9/27/22.
//

#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "degree.h"
using std::string;
using std::cout;
//using std::endl;

class Student
{
public:
    const static int daysArray = 3;
    
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int days[daysArray];
    DegreeType degreeType;//
public:
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeType degreeType);//full constructor
    ~Student();//destructor
    
    //getters
    string getID();
    string getTitle();
    string getFName();
    string getLName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeType getDegreeType();
    
    //setters • mutators
    void setID(string studentID);
    void setFName(string firstName);
    void setLName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeType(DegreeType dt);; 
    
    static void printHeader(); //displays header for data
    
    void print();
};



