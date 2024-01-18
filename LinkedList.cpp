//
//  LinkedList.cpp
//  Homework 1
//
//  Created by Ava Gonick on 7/5/23.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;

}


LinkedList::LinkedList(const LinkedList& rhs){
    //if the rhs head is a nullptr the new head is also just the nullptr
    if(rhs.head == nullptr){
        head = nullptr;
        return;
    }

   //create a node to loop through the while loop
    Node* p = rhs.head;
    
    //create a current node to start the new linked list
    Node* current = new Node;
    
    //set head to point at current, which at this moment is the top of the new linked list
    head = current;
  
    //loop through the original linked list, in each iteration create a new node for the next node and point the current node at it, stop when the next node is the nullptr
    while( p->next != nullptr){
    
        
        //set the current value  to the p-value;
        current->value = p->value;
        
        //make next node for current node to point at
        Node* after = new Node;
        current->next = after;
        
        
        //increment p to point to the next pointer in the original linked list
        p = p-> next;
        
        //set current equal to after so it now points to the next node in the linked list
        current = after;
    }
    
    //once go through the loop, this is at the last value in the linked list, set the value to the value from the original linked list and point the next value as the nullptr
    current-> value = p->value;
    current-> next = nullptr;

}

LinkedList::~LinkedList(){
    //set p to the head
    Node* p;
    p = head;
    
    //loop through the linked list deleting each node, once get to the nullptr stop deleting becuase this is the end of the linked list
    while( p != nullptr){
        Node* q;
        //reassign q to p next so that p can be deleted without the next being lost 
        q = p->next;
        delete p;
        p = q;

    }
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs){
    
    if(this == &rhs){
        return *this;
    }
    
    
    Node* p = head; //create a node to loop through the original Linked List
    //loop through the Linked List deleting every value
    while( p != nullptr){
            Node* q;
            //reassign q to p next so that p can be deleted without the next being lost
            q = p->next;
            delete p;
            p = q;
            
    }
    
    //after the original linked list has been deleted, create a new LinkedList with the same values as rhs, setting head to point towards this list
    
   //if the rhs head is a nullptr the new head is also just the nullptr
    if(rhs.head == nullptr){
        head = nullptr;
        return *this;
    }
    
    //create a node to loop through the rhs LinkedList
    Node* loop = rhs.head;
    
    //create a current node to create new nodes for a LinkedList that is equivalent in value to the rhs LinkedList
    
    Node* current = new Node;
    
    
    //set head to point at current, which at this moment is the top of the new linked list
    head = current;
    
    //loop through the original linked list, in each iteration create a new node for the next node and point the current node at it, stop when the next node is the nullptr
    while( loop->next != nullptr){
        //set the current value  to the p-value;
        current->value = loop->value;
        
        //make next node for current node to point at
        Node* after = new Node;
        current->next = after;
        
        //increment p to point to the next pointer in the original linked list
        loop = loop-> next;
        
        //set current equal to after so it now points to the next node in the linked list
        current = after;
        
    }
    
    //once go through the loop, this is at the last value in the linked list, set the value to the value from the original linked list and point the next value as the nullptr
    current-> value = loop->value;
    current-> next = nullptr;
    return *this;
}

void LinkedList::insertToFront(const ItemType &val){
    Node* insert = new Node;
    insert -> value = val;
    insert -> next = head;
    head = insert;
}

void LinkedList::printList() const{//go back and double check how this should be printed
    if(head == nullptr)
        return;
    Node* loop = head;
    while(loop != nullptr){
        cout << loop -> value << " ";
        loop = loop->next;
    }
    cout << endl;
}

bool LinkedList::get(int i, ItemType& item) const{
    int it = 0;
    Node* loop = head;
    while(loop != nullptr){
        if(it == i){
            item = loop->value;
            return true;
        }
        loop = loop->next;
        it++;
    }
    return false;
    
}

int LinkedList::size() const{
    Node* loop = head;
    int i = 0;
    while(loop != nullptr){
        i++;
        loop = loop -> next;
    }
    return i;
}

void LinkedList::reverseList(){
    //set one node to the current head
    //iterate through the end using an different node
    //set the end node to the head
    //then iterate through again ending one before the next one using the size function
    //set the next of the previous pointer there
    
    //if just the nullptr return 
    if( head == nullptr){
        return;
    }
    Node* hold = head;
    int i = size();
    
    //loop through the Linked list to the end
    Node* loop = head;
    while(loop ->next != nullptr){
        loop = loop -> next;
    }
    
    //set the new head at the end of the linkedList
    head = loop;
    
    //create a reverse node to iterate through the LinkedList starting at the end, so that the next pointers of these can be reset creating a reversed LinkedList
    Node* reverse = loop;
    
    //iterate through size-1 times (because need to reset the next value for every single Node to the Node before it except for the last node which needs to be reset to the null ptr)
    for(i = i - 2; i >= 0; i--)
    {
        //create a node that starts are the original beginning
        Node* revprev = hold;
        
        //create a counter so that you can iterate through the LinkedList landing at the i-1 position. the i-1 position is going to be one before where reverse is set
        int check = 0;
        
        //loop through the linkedlist, ending one before where reverse is currently set
        while(check < i){
            revprev = revprev->next;
            check++;
           
        }
        
        //set reverse to reprev which is one before where reverse is in the original Linked List
        reverse -> next = revprev;
        
        //set reverse to reverse next, which would be considered one previous in the original LinkedList
        reverse = reverse->next;
    }
    
    //the last Node in the list needs its next value to be reset to the null pointer
    reverse->next = nullptr;
}

void LinkedList::printReverse() const {
  if (head == nullptr)
      return;

    Node* hold = head;
    int i = size();
    
    //iterate through size times
    for(i = i - 1; i >= 0; i--)
    {
        //create a node that starts are the original beginning
        Node* revprev = hold;
        
        //create a counter so that you can iterate through the LinkedList landing at the i-1 position, the will be the LinkedList item to print out
        int check = 0;
        
        //loop through the linkedlist, ending one before the last LinkedList item that was printed out
        while(check < i){
            revprev = revprev->next;
            check++;
           
        }
        
        //print out the item
        cout << revprev->value << " ";
      
    }
    
    cout << endl;
    
   
}
    
void LinkedList::append(const LinkedList& other){
    
    //if appending a nullptr return
    if(other.head == nullptr)
        return;
    
    
    //create a node for looping through the appending function
    Node* loop = other.head;
    
    //create a new node to hold the new nodes to be appended
    Node* append = new Node;
    
    //create a node to hold where the start of the new appending node is at
    Node* hold = append;
    
    
    //loop through setting values, breaking out once the next value is a nullptr
    while( loop != nullptr){
        
        //set value to loops new value
        append -> value = loop-> value;
        
        if(loop->next == nullptr){
            append-> next = nullptr;
            break;
        }
        
        else{
            Node* after = new Node;
            append -> next = after;
            loop = loop -> next;
            append = append->next;
        }
    }
    
    //if size is 0, then just set the head to start where the newly made appending linkedlist is
    if(size() == 0){
        head = hold;
        return;
    }
    //if size is not 0, then set the end of the original LinkedList to have its next value point where the newly made appending LinkedList is
    else{
        //get to the end of the original linked list
        Node* p = head;
        //if head is not nullptr loop through to the end of the list
        while(p-> next != nullptr){
                p = p->next;
            }
        
        p->next = hold;
    }
}
    
   
    


void LinkedList::swap(LinkedList &other){
    //swap the head values to swap the LinkedLists
    Node* hold = other.head;
    other.head = head;
    head = hold;
}
