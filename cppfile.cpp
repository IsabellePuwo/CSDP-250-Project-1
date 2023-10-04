// Isabelle Njunda Puwo
// Project 1
// cppfile.cpp
// CSDP250 Project 1
//
//  Created by Isabelle Puwo on 10/1/23.
//

#include <stdio.h>
#include "Header.h"
#include<iostream>

using namespace std;


StudentList::StudentList(){
    head = nullptr;
}

StudentList::~StudentList(){
    ListNode* nodePtr = nullptr;
    ListNode* nextNode = nullptr;
    nodePtr = head;
    
    while(nodePtr){
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void StudentList::appendNode(int ID, double gpa){
    
    ListNode* newNode;
    ListNode* nodePtr;
    newNode = new ListNode;
    newNode->ID = ID;
    newNode->gpa = gpa;
    newNode->next = nullptr;
    
    if(!head){
        head = newNode;
    } else{
            nodePtr = head;
            while(nodePtr->next)
                nodePtr = nodePtr->next;
                nodePtr->next = newNode;
                
        }
    
}

void StudentList::displaylist() const
{
    ListNode* nodePtr;
    nodePtr  = head;
    
    while(nodePtr){
        cout<< endl << "Student ID: "<< nodePtr->ID << " Student GPA: "<<nodePtr->gpa << "\n";
        nodePtr = nodePtr->next;
    }
}

void StudentList::deleteNode(int ID){
    ListNode* nodePtr;
    ListNode* prevPtr = nullptr;
    if(!head){
        cout<< "\n Nothing to delete! \n";
        return;
    }
    if(head->ID == ID){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else {
        nodePtr = head;
        while(nodePtr->ID != ID && nodePtr->next != nullptr){
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }
    }
    if(nodePtr){
        prevPtr->next = nodePtr->next;
        delete nodePtr;
    }
    else{
        cout<< endl << "Sorry, this ID does not exist! "<<endl;
    }
}


void StudentList:: insertionNode(int ID, double GPA){
    ListNode *prevNode, *newNode;
    newNode = new ListNode;
    newNode->ID = ID-1;
    newNode -> gpa = GPA;
    
    if(head == NULL || head->ID >= newNode->ID){
        newNode->next = head;
        head = newNode;
    }
    else {
        prevNode = head;
        while(prevNode->next != NULL && prevNode->next->ID < prevNode->ID){
            prevNode = prevNode->next;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
  
    
}


void StudentList:: checkList(int ID, double GPA){
    ListNode *nodePtr = head;
    while (nodePtr != nullptr)
    {
        if (nodePtr->ID == ID){
            cout<< endl << "Student inserted successfully" <<endl;
            insertionNode(ID, GPA);
            return;
        }
        nodePtr = nodePtr->next;
    }
    cout<<"Sorry, this ID does not exist!"<<endl;
}


void StudentList:: checkList2(int ID){
    ListNode *nodePtr = head;
    while (nodePtr != nullptr)
    {
        if (nodePtr->ID == ID){
            cout<< endl << "Student deleted successfully" <<endl;
            deleteNode(ID);
            return;
        }
        nodePtr = nodePtr->next;
    }
    cout<<"Sorry, this ID does not exist!"<<endl;
}
