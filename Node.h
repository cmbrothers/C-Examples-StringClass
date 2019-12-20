/*
Name: Caleb Brothers
Class: CS132
Section: S
Description: Node class. Single container for doubly
linked list class which holds  CBString data and references to previous 
and next containers if any, NULL otherwise.
*/

#ifndef NODE_H
#define NODE_H
template<typename T>
class Node {
public:
   Node();
   Node(T& str); //Constructor
   T element; //Data cell
   Node* prev; //pointer to previous cell if not tail, otherwise NULL
   Node* next; //pointer to next cell if not head, otherwise NULL
};

template<typename T>
Node<T>::Node() {

}
template<typename T>
Node<T>::Node(T& str) {
   element = str;
}

#endif

