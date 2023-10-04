// Isabelle Njunda Puwo 
//  Header.h
//  CSDP250 Project 1
//
//  Created by Isabelle Puwo on 10/1/23.
//

#ifndef Header_h
#define Header_h

#include <stdio.h>
class StudentList{
private:
    struct ListNode{
        int ID;
        double gpa;
        struct ListNode* next;
    };
    ListNode* head;
public:
    StudentList();
    ~StudentList();
    void appendNode(int, double);
    void deleteNode(int);
    void displaylist() const;
    void insertionNode(int, double);
    void checkList(int, double);
    void checkList2(int);
};

#endif /* Header_h */
