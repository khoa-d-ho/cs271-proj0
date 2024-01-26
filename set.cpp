#include <iostream>
#include "set.h"
#include <string>
#include <chrono>
using namespace std;

//=============================================
// default function
// The function creates a new empty List 
// Parameter: void
// Return value: None
//=============================================
template <typename T>
Set<T>	::Set(void)
{
	head = NULL; 
}

//=============================================
// copy function 
// The function creates a new List from an existing one.
// Parameter: List (mylist)
// Return value: None
//=============================================

template <typename T>
Set<T>	::Set(const Set<T> &mylist) 
{

    Node *otherPtr = mylist.head;
    Node *last = NULL;

    while (otherPtr != NULL)
    {
        Node *newNode = new Node;
        newNode -> item = otherPtr -> item; 
        newNode -> next = NULL;

        if (last == NULL)
        {
            head = newNode;
        }
        else
        {
            last->next = newNode;
        }

        last = newNode;
        otherPtr = otherPtr->next;
    }
}

//=============================================
// destructor function
// The function cleans up the memory of the list.
// Parameter: void
// Return value: None
//=============================================

template <typename T>
Set<T>	::~Set(void)
{

    Node *ptr = head;
    while (ptr != NULL)
    {
        Node *nextNode = ptr->next;
        delete ptr;
        ptr = nextNode;
    }
}

    // Insert 




template <class T>
void		Set<T>::insert		( const T &value )
{
	Node *current = head;
	while ( current != NULL )
	{
		if (current->item == value)
		{
			return;
		}
		current = current->next;
	}
	Node *newNode = new Node;
	newNode->item = value;
	newNode->next = head;
	head = newNode;
}

    // Remove 
template <typename T>
void 	Set<T>::remove(const T& value) 
{
        Node* current = head;
        Node* previous = NULL;

        while (current != NULL && current->item != value) 
        {
            previous = current;
            current = current->next;
        }

        if (current != NULL) 
        {
            if (previous != NULL) 
            {
                previous->next = current->next;
            } 
            else 
            {
                head = current->next;
            }
            delete current;
        }
}

    // cardinality 
template <typename T>
int 	Set<T>::cardinality(void) const 
{
        int count = 0;
        Node* current = head;

        while (current != NULL) 
        {
            count++;
            current = current->next;
        }

        return count;
}

    // empty
template <typename T>
bool 	Set<T>::empty(void) const 
{
        return head == NULL;
}

    // contains 
// template <typename T>
// bool 	Set<T>::contains(const T& value) const
// {
//         Node* current = head;

//         while (current != NULL)
//         {
//             if (current->item == value) 
//             {
//                 return true;
//             }
//             current = current->next;
//         }

//         return false;
// }

template <typename T>
bool Set<T>::contains(const T& value) const {
    Node* current = head;
    while (current != NULL) {
        if (current->item == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

    // Equality operator
template <typename T>    
bool 	Set<T>::operator==(const Set<T>& mylist) const 
{
        if (cardinality() != mylist.cardinality()) 
        {
            return false;
        }

        Node* current = head;
        while (current != NULL) 
        {
            if (!mylist.contains(current->item)) 
            {
                return false;
            }
            current = current->next;
        }

        return true;
}

    // Subset operator
template <typename T>
bool 	Set<T>::operator<=(const Set<T>& mylist) const 
{
        Node* current = head;
        while (current != NULL) 
        {
            if (!mylist.contains(current->item)) 
            {
                return false;
            }
            current = current->next;
        }

        return true;
    }

    // Union operator
// template <typename T>
// Set<T> 	Set<T>::operator+(const Set<T>& mylist) const 
// {
//         Set<T> result;
//         Node* current = mylist.head;
//         while (current != NULL) 
//         {
//             result.insert(current->item);
//             current = current->next;
//         }

//         current = mylist.head;
//         while (current != NULL) 
//         {
//             result.insert(current->item);
//             current = current->next;
//         }

//         return result;
// } sai


template <typename T>
Set<T> Set<T>::operator+(const Set<T>& mylist) const {
    Set<T> result;

    Node* current = mylist.head;
    while (current != NULL) {
        result.insert(current->item);
        current = current->next;
    }
    current = head;
    while (current != NULL) {
        result.insert(current->item);
        current = current->next;
    }

    return result;
}


    // Intersection operator
template <typename T>
Set<T> 	Set<T>::operator&(const Set<T>& mylist) const 
{
        Set<T> result;
        Node* current = head;
        while (current != NULL) 
        {
            if (mylist.contains(current->item)) 
            {
                result.insert(current->item);
            }
            current = current->next;
        }

        return result;
}

    // Difference operator
template <typename T>
Set<T> 	Set<T>::operator-(const Set<T>& mylist) const 
{
        Set<T> result;
        Node* current = head;
        while (current != NULL) 
        {
            if (!mylist.contains(current->item)) 
            {
                result.insert(current->item);
            }
            current = current->next;
        }

        return result;
}

template <typename T>
string Set<T>::to_string() const 
{
    string result = ""; 
    Node* current = head; 
    while (current != NULL)
    {
        result += std::to_string(current->item);
        if (current->next != NULL)
        {
            result += " "; 
        }
        current = current->next;
    }
    result += ""; 
    return result;
}





