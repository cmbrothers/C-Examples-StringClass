/*
Name: Caleb Brothers
Class: CS132
Section: S
Description: Doubly Linked List class of Node containers each carrying a 
CBString entry for indexing, search and ordering operations.
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Node.h"

using namespace std;
template<typename T>
class DoubleLinkedList {
//outputs entire list witha space seperating each entry


public:
   DoubleLinkedList();//default constructor
   DoubleLinkedList(const DoubleLinkedList<T>& dll); //copy constructor
   ~DoubleLinkedList(); //destructor

   //deletes contents of list before repopulating with contents of another
   //to make them equal.
   T& operator=(const T& dll);

   bool insert(const T& str); //performs ordered insert of string
   bool remove(const T& str); //searches for and removes string if 
                                     //present in list.
   void resetIteration() const; //sets iteratorto first element in list,
                                //head or pullptr.
   T& next() const; //returns string at iterator current loc 
                           //and advnaces iterator
   bool hasNext() const; //checks if there is another element in list 
                         //after current.
   int getNodeCount() const; //outputs total nodes in list.

   friend ostream& operator<<(ostream& ostrm, 
          const DoubleLinkedList<T>& dll) {
      Node<T> *temp = dll.head;
      while (temp != nullptr) {
         ostrm << temp->element << " ";
         temp = temp->next;
      }
      /*Reverse order test, making sure tail updates correctly and
      bi-directional linking is correct. PASSED
      Node *temp2 = dll.tail;
      while (temp2 != nullptr) {
         ostrm << temp2->element << " ";
         temp2 = temp2->prev;
      }
      */
      return ostrm;
   }
private:
   int nodeCount;
   Node<T> *head;
   Node<T> *tail;
   mutable Node<T> *iter;
   mutable Node<T> *tempIter;
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
   head = nullptr;
   tail = nullptr;
   nodeCount = 0;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& dll) {
   head = nullptr;
   tail = nullptr;
   nodeCount = 0;
   
   dll.resetIteration();

   while (dll.hasNext()) {
      insert(dll.next());
   }
   insert(dll.next());

}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
   nodeCount = 0;
   while (tail != nullptr) {
      Node<T> *temp = tail;
      tail = temp->prev;
      if (tail != nullptr) {
         tail->next = nullptr;
         temp->prev = nullptr;
      }
      else {
         head = tail;
      }
      delete temp;
   }
}

template<typename T>
T& DoubleLinkedList<T>::operator=(const T& dll) {
   nodeCount = 0;
   while (tail != nullptr) {
      Node<T> *temp = tail;
      tail = temp->prev;
      if (tail != nullptr) {
         tail->next = nullptr;
         temp->prev = nullptr;
      }
      else {
         head = tail;
      }

      delete temp;
   }

   dll.resetIteration();

   while (dll.hasNext()) {
      insert(dll.next());
   }
   insert(dll.next());

   return *this;
}
template<typename T>
bool DoubleLinkedList<T>::insert(const T& string) {
   Node<T> *temp = new Node<T>;
   temp->element = string;
   temp->next = nullptr;
   temp->prev = nullptr;
   if (head == nullptr) {
      head = temp;
      tail = temp;
      temp = nullptr;
      nodeCount++;
      return true;
   }
   Node<T> *search = head;
   Node<T> *fore = head->next;
   while (search != nullptr) {
      if (search->element == temp->element) {
         delete temp;
         return false;
      }
      search = search->next;
   }
   search = head;
   if (head->element > temp->element) {
      temp->next = head;
      head = temp;
      temp = nullptr;
      nodeCount++;
      return true;
   }
   while (search != nullptr) {
      if ((search->element < temp->element && fore == nullptr)
         || (search->element < temp->element && temp->element 
         < fore->element)){
         temp->prev = search;
         temp->next = fore;
         search->next = temp;
         if (fore != nullptr) {
            fore->prev = temp;
         }
         if (fore == nullptr) {
            tail = temp;
         }
         temp = nullptr;
         nodeCount++;
         return true;
      }
      search = search->next;
      fore = fore->next;
   }   
   return false;
}
template<typename T>
bool DoubleLinkedList<T>::remove(const T& string) {
   Node<T> *temp = head;
   Node<T> *follower = head->prev;
   Node<T> *leader = head->next;
   while (temp != nullptr) {
      if (temp->element == string) {      
         if (follower == nullptr) {
            leader->prev = temp->prev;
            head = leader;
            delete temp;
            nodeCount--;
            return true;
         }
         if (leader == nullptr) {
            follower->next = temp->next;
            tail = follower;
            delete temp;
            nodeCount--;
            return true;
         }
         leader->prev = temp->prev;
         follower->next = temp->next;
         delete temp;
         nodeCount--;
         return true;
      }
      else {
         temp = temp->next;
         if (temp == nullptr) {
            return false;
         }
         follower = temp->prev;
         leader = temp->next;
      }
   }
   return false;
}
template<typename T>
int DoubleLinkedList<T>::getNodeCount() const {
   return nodeCount;
}
template<typename T>
void DoubleLinkedList<T>::resetIteration() const {
   Node<T> *temp = head;
   iter = temp;
}

template<typename T>
T& DoubleLinkedList<T>::next() const {
   tempIter = iter;
   iter = iter->next;
   return tempIter->element;
}
template<typename T>
bool DoubleLinkedList<T>::hasNext() const {
   if (iter->next != nullptr) {
      return true;
   }
   return false;
}  

#endif
