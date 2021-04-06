//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once
#include <string>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template<class T>
class LinkedList: public LinkedListInterface<T>{
private:
	struct Node {
	 T data; // The data we are storing
	 Node* next; // A pointer to the next Node 
	 Node(const T& the_data, Node* next_val = NULL) :
	   data(the_data) {next = next_val;}
	};
	
	Node *mylist;
	int num_items;

public:

	LinkedList(void) {
		cout << "In constructor" << endl;
		mylist = NULL;
		num_items = 0;
	};
	virtual ~LinkedList(void) {
		while(mylist != NULL) {
			Node *current = mylist;
			mylist = mylist->next;
			delete current;
		}
	};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertHead(T value)
	{
		Node *ptr = mylist;
		mylist = new Node(value);
		mylist->next = ptr;
		cout << "In insertHead" << endl;

	};

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertTail(T value)
	{
		cout << "In insertTail"<<endl;
		Node *ptr = mylist;
		if(mylist == NULL){
			mylist = new Node(value, NULL);
		} else {
			while(ptr != NULL){
				//cout << ptr<<" data "<<ptr->data<<" next "<<ptr->next<<endl;
				if(ptr->next == NULL) {
					ptr->next = new Node(value, NULL);
					break;
				} else {
					ptr = ptr->next;
				}
			}
		}
		num_items++;
	};

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	virtual void insertAfter(T value, T insertionNode)
	{
		
	};

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	virtual void remove(T value)
	{
		cout << "In remove, searching for: "<< value <<endl;
		Node *ptr = mylist;

		//check first value
		if (value == ptr->data){
					cout << "Found value at first node: " << ptr->data << ", deleting now " << endl;
					Node *current = ptr;
					mylist = current->next;

					delete current;
					num_items--;
					return;
				}
		else {
				//check the rest 
				cout << "Checking list:" << endl;
				ptr = mylist;
				while(ptr->next != NULL) {
					if (value == ptr->next->data){
						cout << "Gotcha. Deleting now" << endl;
						Node *current = ptr->next;
						ptr->next = ptr->next->next;
						delete current;
						num_items--;
						break;
					}
					else {
						cout << "Value here is: " << ptr->next->data << ", not " << value << ". Moving to ptr->next" << endl;
						ptr = ptr->next;
					}
				
			}
		}
		
	};

	/*
	clear

	Remove all nodes from the list.
	*/
	virtual void clear()
	{
		
	};

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	virtual T at(int index)
	{
		
	};

	/*
	size

	Returns the number of nodes in the list.
	*/
	virtual int size()
	{
		
	};

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	virtual string toString()
	{
		stringstream ss;
		for(Node *ptr =mylist; ptr != NULL; ptr = ptr->next){
			ss <<"ptr "<<ptr<<" val "<<ptr->data<<" next "<<ptr->next<<endl;
		}
		
		return (ss.str());
	};

};
