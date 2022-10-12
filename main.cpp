//
//  main.cpp
//  C867
//
//  Created by Troy Cost on 9/27/22.
//


#include <iostream>
#include "roster.h"
using namespace std;
//using std::endl;

int main()
{
     cout<< "Course: C867 • Scripting and Programming Applications\n" << "Programming Language: C++\n" << "ID: 002197948\n" << "Name: Troy Cost" << std::endl << std::endl;
        


   //long string to parse
    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Troy,Cost ,tcost@wgu.edu,29,15,19,22,SOFTWARE"
        };
              
    
    Roster classRoster;
    const int studentDataTable = 5;//sets array size to 5 for each student
    
    for (int i = 0; i < studentDataTable; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students:" << std::endl;
    classRoster.printAll();
    cout << std::endl;
    //display all students
        
        
    cout << "Displaying invalid email addresses: " << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    //display all students with an incorrectly formatted email address
    
    cout << "Displaying average days per class for each student:" << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
    classRoster.printAverageDays(classRoster.classRosterArray[i]->getID());
    }
    cout << std::endl;
    //display the average number of days each student spends in 3 classes
    
    cout << "Displaying all software students:" << std::endl;
    classRoster.printByDegreeType(SOFTWARE);
    cout << std::endl;
    //display all students in the software degree program
    
        
    cout << "Remove student A3." << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    //remove student A3 and print all remaining students
    std::cout << "Printing all students " << std::endl << std::endl;
        classRoster.printAll();

    std::cout << "Removing A3 again " << std::endl << std::endl;
    classRoster.remove("A3");

}
