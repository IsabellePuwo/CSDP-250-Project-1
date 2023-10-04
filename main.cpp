//
//  main.cpp
//  CSDP250 Project 1
//
//  Created by Isabelle Puwo on 10/1/23.
//

#include <iostream>
#include "Header.h"
using namespace std;

int main(){
    StudentList Student;
    int studentID;
    double studentgpa;
    int choice = 0;
    
    for(int i = 0; i < 10; i++){
        studentID = 132677 + i * 4;
        cout<< "Please enter student "<< "#" << i +1 << " GPA" <<endl;
        cin>> studentgpa;
        Student.appendNode(studentID, studentgpa);
    }

    while (choice != 5)
    {
        cout<< endl <<"Welcome :) what would you like to do?" << endl;
        cout<<"1. Append a Node\n";
        cout<<"2. Insert a Node\n";
        cout<<"3. Delete a Node\n";
        cout<<"4. Display List\n";
        cout<<"5. Exit Program\n";
        cout<<"Please enter your choice: "<< endl;
        cin>> choice;
        
        switch(choice){
            case 1:
                cout<<"Please enter student ID: "<<endl;
                cin>> studentID;
                cout<< "Please enter student's GPA: "<< endl;
                cin>> studentgpa;
                Student.appendNode(studentID, studentgpa);
                break; 
            case 2:
                cout<< "Please insert the 6 digit ID number: "<< endl;
                cin>> studentID;
                cout<< "Please enter student's GPA: " << endl;
                cin>> studentgpa;
                Student.checkList(studentID, studentgpa);
                break;
                
            case 3:
                cout<<"Please choose student ID to delete: "<< endl;
                cin>> studentID;
                Student.checkList2(studentID);
                break;
                
            case 4:
                Student.displaylist();
                break;
                
            case 5:
                cout<< "Exiting Program....."<< endl;
                break;
                
            default:
                cout<< "Invalid option, please choose the numbers displayed on the screen! \n";
        }
    }

    return 0;
    
}


