//==============================================
//==============================================

#include <iostream> 
#include <string> 
#include <chrono>
using namespace std; 

#ifndef SET_H
#define SET_H

template <typename T> 
class Set
{
private:
	// struct for Node for linked list
	struct Node
	{
		T		item;
		Node 	*next;
	};
	
	Node	*head;		// the pointer for the linked list
	
public: 
			Set				( void ); 
			Set				( const Set<T> &mylist );
			~Set			( void );
void		insert			( const T& value ); 
void 		remove 			( const T& value ); 
int			cardinality 	( void ) const; 
bool 		empty			( void ) const; 
bool contains(const T& value) const; 

bool		operator==		( const Set<T> &mylist) const;
bool 		operator<=		(const Set<T> &mylist) const;
Set<T> 		operator+		(const Set<T> &mylist) const; 
Set<T> 		operator&		(const Set<T> &mylist) const;
Set<T> 		operator-		(const Set<T> &mylist) const;
string 		to_string		( void ) const; 

friend ostream & operator<< ( ostream &os, Set<T> &mylist )
{
	Node *ptr = mylist.head;
	os << "[ ";
	while ( ptr != NULL )
	{
		if ( ptr->next != NULL )
			os << ptr->item << ", ";
		else
			os << ptr->item << " ";
		ptr = ptr->next;
	}
	os << "]";
	return os;	
}
};


//#include "set.cpp" 
#endif
