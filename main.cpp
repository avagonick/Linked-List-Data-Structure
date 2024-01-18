//
//  main.cpp
//  Homework 1
//
//  Created by Ava Gonick on 7/5/23.
//
#include "LinkedList.h"
#include <iostream>
#include <cassert>
using namespace std;
int main() {
    
    
/*
     //test the copy constructor
     
     //make sure it works when copy constructed to a nullptr
     
     //these lines double check if it can properly copy construct Hello over
     LinkedList* copyconstruct1 = new LinkedList;
     copyconstruct1->insertToFront("0");
     copyconstruct1->insertToFront("l");
     copyconstruct1->insertToFront("l");
     copyconstruct1->insertToFront("E");
     copyconstruct1->insertToFront("H");
     LinkedList copyconstruct2(*copyconstruct1);
     cout << endl;
     copyconstruct2.printList();
     string get;
     assert(copyconstruct1->size() == 5 && copyconstruct1->get(0, get) && get == "H");
     assert(copyconstruct1->size() == 5 && copyconstruct1->get(1, get) && get == "E");
     assert(copyconstruct1->size() == 5 && copyconstruct1->get(2, get) && get == "l");
     assert(copyconstruct1->size() == 5 && copyconstruct1->get(3, get) && get == "l");
     assert(copyconstruct1->size() == 5 && copyconstruct1->get(4, get) && get == "0");
     
     assert(copyconstruct2.size() == 5 && copyconstruct2.get(0, get) && get == "H");
     assert(copyconstruct2.size() == 5 && copyconstruct2.get(1, get) && get == "E");
     assert(copyconstruct2.size() == 5 && copyconstruct2.get(2, get) && get == "l");
     assert(copyconstruct2.size() == 5 && copyconstruct2.get(3, get) && get == "l");
     assert(copyconstruct2.size() == 5 && copyconstruct2.get(4, get) && get == "0");
     
     delete copyconstruct1;
     
     
     //check if it can copy construct a LinkedList of size 1
     LinkedList* copyconstruct3 = new LinkedList;
     copyconstruct3->insertToFront("A");
     LinkedList copyconstruct4= *copyconstruct3;
     cout << endl;
     copyconstruct4.printList();
     assert(copyconstruct3->size() == 1 && copyconstruct3->get(0, get) && get == "A");
     assert(copyconstruct4.size() == 1 && copyconstruct4.get(0, get) && get == "A");
     
     delete copyconstruct3;
     
     
     //check copy construct with a LinkedList that is just a nullpointer
     LinkedList* copyconstruct5 = new LinkedList;
     LinkedList copyconstruct6 = *copyconstruct5;
     assert(copyconstruct5->size() == 0 && !copyconstruct5->get(0, get));
     assert(copyconstruct6.size()== 0 && !copyconstruct6.get(0,get));
     
     delete copyconstruct5;
     
     
     //test copying over one to another both hold values
     LinkedList assignopp1;
     assignopp1.insertToFront("K");
     assignopp1.insertToFront("C");
     assignopp1.insertToFront("A");
     assignopp1.insertToFront("W");
     LinkedList* assignopp2 = new LinkedList;
     assignopp2->insertToFront("M");
     assignopp2->insertToFront("P");
     assert(assignopp2->size() == 2 && assignopp2->get(0,get) && get == "P");
     assignopp2->printList();
     *assignopp2 = assignopp1;
     assert(assignopp1.size()==4 && assignopp1.get(0,get) && get == "W");
     assert(assignopp2->size() == 4  && assignopp2->get(0,get) && get == "W");
     assignopp1.printList();
     assignopp2->printList();
     delete assignopp2;
     
     //test copying over one to another copy holds values original is null pointer
     LinkedList assignopp3;
     assignopp3.insertToFront("what");
     assignopp3.insertToFront("is");
     assignopp3.insertToFront("up");
     LinkedList assignopp4;
     assignopp4.printList();
     assignopp4 = assignopp3;
     assignopp4.printList();
     assignopp3.printList();
     assert(assignopp4.size() == 3 && assignopp4.get(1, get) && get == "is");
     assert(assignopp3.size() == 3 && assignopp3.get(1, get ) && get == "is");
     
     assignopp3 = assignopp3;
     assert(assignopp3.size() == 3 && assignopp3.get(1, get ) && get == "is");
     
     
     
     
     //test copy one over to another original holds values other holds nothing
     LinkedList assignopp5;
     assignopp5.printList();
     assignopp4 = assignopp5;
     assignopp4.printList();
     assert(assignopp4.size() == 0);
     assignopp4 = assignopp4;
     assert(assignopp4.size() == 0);
     
     
     
     
     //test copy one over to another both hold only one values
     assignopp5.insertToFront("hi");
     LinkedList assignopp6;
     assignopp6.insertToFront("what");
     assignopp6.printList();
     assignopp6 = assignopp5;
     assignopp6.printList();
     assert(assignopp6.size() == 1 && assignopp6.get(0,get) && get == "hi");
     
     assignopp6 = assignopp6;
     assert(assignopp6.size() == 1 && assignopp6.get(0,get) && get == "hi");
     
     
     
     //test get
     ItemType check;
     
     LinkedList get1;
     get1.insertToFront("last nfourth");
     get1.insertToFront("third");
     get1.insertToFront("second");
     get1.insertToFront("first");
     
     LinkedList get2;
     
     //test first item
     assert(get1.get(0, check) && check == "first");
     
     //test get item of empty linked list
     assert(!get2.get(0,check) && check == "first");
     
     //test middle item
     assert(get1.get(2, check) && check == "third");
     
     
     //test last item
     assert(get1.get(3, check) && check == "last nfourth");
     
     //test getting an item out of range
     assert(!get1.get(4, check) && check == "last nfourth");
     
     
     //check reverse linked list
     LinkedList Reverse;
     
     //check nullptr just stays nullptr
     
     Reverse.reverseList();
     
     Reverse.printList();
     
     assert(!Reverse.get(0, check) && Reverse.size() == 0);
     
     if(Reverse.size() == 0){
     cout << "this is the nullptr :)";
     }
     
     
     //check linkedList 1 item stays the same
     Reverse.insertToFront("front");
     
     Reverse.reverseList();
     Reverse.printList();
     assert(Reverse.size() == 1 && Reverse.get(0, check ) && check == "front" );
     
     
     //check linkedlist 2 items has a swap
     
     Reverse.insertToFront("second");
     Reverse.printList();
     Reverse.reverseList();
     Reverse.printList();
     assert(Reverse.size() == 2 && Reverse.get(1, check ) && check == "second");
     
     //check linkedlist more than 2 items gets reversed
     
     Reverse.insertToFront("newest");
     Reverse.printList();
     Reverse.reverseList();
     Reverse.printList();
     assert(Reverse.size() == 3 && Reverse.get(0, check) && check == "second");
     assert(Reverse.size() == 3 && Reverse.get(1, check) && check == "front");
     assert(Reverse.size() == 3 && Reverse.get(2, check) && check == "newest");
     
     Reverse.insertToFront("will be at back");
     Reverse.printList();
     Reverse.reverseList();
     Reverse.printList();
     
     
     //now check print reverse
     
     LinkedList PrintRev;
     
     //check nullptr
     
     PrintRev.printReverse();
     cout << endl;
     
     //check size 1
     
     PrintRev.insertToFront("front");
     PrintRev.printList();
     cout << endl;
     PrintRev.printReverse();
     cout << endl;
     
     //check size 2
     PrintRev.insertToFront("second");
     PrintRev.printList();
     cout << endl;
     PrintRev.printReverse();
     cout << endl;
     //check size 3
     PrintRev.insertToFront("third");
     PrintRev.printList();
     cout << endl;
     PrintRev.printReverse();
     cout << endl;
     //check size 4
     PrintRev.insertToFront("fourth");
     PrintRev.printList();
     cout << endl;
     PrintRev.printReverse();
     cout << endl;
     
     
     //check the append list function
     
     LinkedList append1;
     LinkedList append2;
     
     //apend to null list together
     append1.append(append2);
     assert(append1.size() == 0);
     assert(append2.size() == 0);
     
     //first is null second is not, second is size 1
     
     append2.insertToFront("list2begin");
     append1.append(append2);
     append2.printList();
     assert(append2.size() == 1 && append2.get(0, check ) && check == "list2begin");
     append1.printList();
     assert(append1.size() == 1 && append1.get(0, check ) && check == "list2begin");
     
     //append size 2 onto a nullptr
     
     LinkedList append3;
     
     append2.insertToFront("newlist2begin");
     cout << "testing a size of two " << endl;
     append3.append(append2);
     append3.printList();
     assert(append3.size() == 2 && append3.get(1, check ) && check == "list2begin");
     assert(append3.size() == 2 && append3.get(0, check ) && check == "newlist2begin");
     
     //first is not null second is null
     LinkedList append4;
     append3.append(append4);
     append3.printList();
     assert(append3.size() == 2 && append3.get(1, check ) && check == "list2begin");
     assert(append3.size() == 2 && append3.get(0, check ) && check == "newlist2begin");
     
     
     //first is only 1 long
     
     LinkedList append5;
     
     append5.insertToFront("begin");
     append5.append(append3);
     append5.printList();
     assert(append5.size() == 3 && append5.get(1, check) && check == "newlist2begin");
     assert(append5.size() == 3 && append5.get(0, check) && check == "begin");
     assert(append5.size() == 3 && append5.get(2, check) && check == "list2begin");
     
     //second is only 1 long
     
     LinkedList append6;
     append6.insertToFront("hi");
     append5.append(append6);
     append5.printList();
     assert(append5.size() == 4 && append5.get(1, check) && check == "newlist2begin");
     assert(append5.size() == 4 && append5.get(0, check) && check == "begin");
     assert(append5.size() == 4 && append5.get(2, check) && check == "list2begin");
     assert(append5.size() == 4 && append5.get(3, check) && check == "hi");
     
     
     //testing appending two of the same together
     
     append3.append(append3);
     append3.printList();
     assert(append3.size() == 4 && append3.get(1, check ) && check == "list2begin");
     assert(append3.size() == 4 && append3.get(0, check ) && check == "newlist2begin");
     assert(append3.size() == 4 && append3.get(3, check ) && check == "list2begin");
     assert(append3.size() == 4 && append3.get(2, check ) && check == "newlist2begin");
     
     //testing the swap function
     
     //test swap two null pointers
     LinkedList swap1;
     LinkedList swap2;
     swap1.swap(swap2);
     assert(swap1.size() == 0);
     assert(swap2.size() == 0);
     
     //test swap first is null and second isnt
     
     LinkedList swap3;
     swap3.insertToFront("front");
     swap1.swap(swap3);
     assert(swap3.size() == 0);
     assert(swap1.size() == 1);
     //test first isnt null and second is
     
     LinkedList swap4;
     LinkedList swap5;
     swap5.insertToFront( "check");
     swap5.swap(swap4);
     assert(swap5.size() == 0);
     assert(swap4.size() == 1);
     
     //test normally swap two, each with size 1
     
     LinkedList swap6;
     
     swap6.insertToFront("hi");
     
     LinkedList swap7;
     swap7.insertToFront( "me");
     swap7.swap(swap6);
     assert(swap7.get(0,check) && check == "hi");
     assert(swap6.get(0, check) && check == "me");
     
     LinkedList swap8;
     swap8.insertToFront("one");
     swap8.insertToFront("two");
     
     LinkedList swap9;
     
     swap9.insertToFront("three");
     swap9.insertToFront("four");
     
     //test normally swap two each with size greater than 1
     
     swap9.swap(swap8);
     
     swap9.printList();
     assert(swap9.get(0,check) && check == "two");
     assert(swap8.get(0, check) && check == "four");
     //test swap two one size greater than 1 and one that is 1
     swap9.swap(swap7);
     assert(swap9.size() == 1);
     assert(swap7.size() == 2);
     //then do the same but the other way around
     swap6.swap(swap8);
     assert(swap6.size() == 2);
     assert(swap8.size() == 1);
     
     //test size function
     
     LinkedList tsize;
     //test size 0
     
     cout << tsize.size() << endl;
     assert(tsize.size() == 0);
     
     //test size 1
     assert(swap8.size() == 1);
     
     
     //test size 2
     assert(swap6.size() == 2);
     
     
     LinkedList ls;
     ls.insertToFront("Hawkeye");
     ls.insertToFront("Thor");
     ls.insertToFront("Hulk");
     ls.insertToFront("Black Widow");
     ls.insertToFront("Iron Man");
     ls.insertToFront("Captain America");
     for (int k = 0; k < ls.size(); k++)
     {
     string x;
     ls.get(k, x);
     cout << x << endl;
     }
     LinkedList lk;
     lk.insertToFront("The Mandalorian");
     lk.insertToFront("Baby Yoda");
     lk.insertToFront("Cara Dune");
     lk.insertToFront("Greef Karga");
     lk.printList();
     lk.printReverse();
     
     LinkedList e1;
     e1.insertToFront("Athos");
     e1.insertToFront("Porthos");
     e1.insertToFront("Aramis");
     LinkedList e2;
     e2.insertToFront("Robin");
     e2.insertToFront("Batman");
     e1.append(e2); // adds contents of e2 to the end of e1
     string m;
     assert(e1.size() == 5 && e1.get(3, m) && m == "Batman");
     assert(e2.size() == 2 && e2.get(1, m) && m == "Robin");
     
     LinkedList e3;
     e3.insertToFront("Jim");
     e3.insertToFront("Oz");
     e3.insertToFront("Paul");
     e3.insertToFront("Kevin");
     e3.reverseList(); // reverses the contents of e1
     assert(e3.size() == 4 && e3.get(0, m) && m == "Jim");
     
 
 */
     LinkedList e4;
     e4.insertToFront("A");
     e4.insertToFront("B");
     e4.insertToFront("C");
     e4.insertToFront("D");
     LinkedList e5;
     e5.insertToFront("X");
     e5.insertToFront("Y");
     e5.insertToFront("Z");
    // e4.swap(e5); // exchange contents of e1 and e2
  //   assert(e4.size() == 3 && e4.get(0, m) && m == "Z");
   //  assert(e5.size() == 4 && e5.get(2, m) && m == "B");
     
     
     

     }
     
