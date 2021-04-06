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
	
	Node *head;
	int num_items;

public:

	LinkedList(void) {
		cout << "In constructor" << endl;
		head = NULL;
		num_items = 0;
	};
	virtual ~LinkedList(void) {
		while(head != NULL) {
			Node *current = head;
			head = head->next;
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
		bool isUnique = true;
		for(Node *ptr=head; ptr != NULL; ptr=ptr->next) {
			if (value == ptr-> data){
				cout << "Not a unique value. Won't add to head" << endl;
				isUnique = false;
			}
		}
		if (isUnique){
		//cout << "Value is unique. Adding to list" << endl;
		Node *ptr = head;
		head = new Node(value);
		head->next = ptr;
		num_items++;
		}

	};

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertTail(T value)
	{
		bool isUnique = true;
		for(Node *ptr=head; ptr != NULL; ptr=ptr->next) {
			if (value == ptr-> data){
				cout << "Not a unique value. Won't add to tail" << endl;
				isUnique = false;
			}
		}

		if (isUnique){
		Node *ptr = head;
		if(head == NULL){
			head = new Node(value, NULL);
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
		}
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
		bool isUnique = true;
		for(Node *ptr=head; ptr != NULL; ptr=ptr->next) {
			if (value == ptr-> data){
				cout << "Not a unique value. Won't add to tail" << endl;
				isUnique = false;
			}
		}

		if (isUnique){
			for(Node *ptr=head; ptr != NULL; ptr=ptr->next){
				if(ptr->data == insertionNode){
					Node *newnode = new Node(value,NULL);
					newnode->next = ptr->next;
					ptr->next = newnode;
					num_items++;
				}
			}
		}
	};

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	virtual void remove(T value)
	{
		cout << "In remove, searching for: "<< value <<endl;
		Node *ptr = head;
		if(num_items == 0) {
			return;
		}

		//check first value
		if (value == ptr->data){
					cout << "Found value at first node: " << ptr->data << ", deleting now " << endl;
					Node *current = ptr;
					head = current->next;

					delete current;
					num_items--;
					return;
				}
		else {
				//check the rest 
				//cout << "Checking list:" << endl;
				ptr = head;
				while(ptr->next != NULL) {
					if (value == ptr->next->data){
						//cout << "Gotcha. Deleting now" << endl;
						Node *current = ptr->next;
						ptr->next = ptr->next->next;
						delete current;
						num_items--;
						break;
					}
					else {
						//cout << "Value here is: " << ptr->next->data << ", not " << value << ". Moving to ptr->next" << endl;
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
		if (head == NULL){
			cout << "List is empty" << endl;
		}
		while(head != NULL) {
			Node *current = head;
			head = head->next;
			delete current;
		}
		num_items = 0;

	};

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	virtual T at(int index)
	{
		if(index >= num_items || index < 0) {
			throw std::out_of_range("At Error");
		} else {
			Node *ptr = head;
			for(int i = 0; i <= index; i++) {
				//cout << "["<<i<<"]="<<ptr->data<<endl;
		  		if(i == (index)) { 
		  			return(ptr->data);
		  		}else {
		  			ptr = ptr->next;
		  		}
			}
		}
	};

	/*
	size

	Returns the number of nodes in the list.
	*/
	virtual int size()
	{
		return num_items;
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
		for(Node *ptr =head; ptr != NULL; ptr = ptr->next){
			//ss <<"ptr "<<ptr<<" val "<<ptr->data<<" next "<<ptr->next<<endl;
			ss << ptr->data << " ";
		}
		
		return (ss.str());
	};

};
