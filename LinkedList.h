#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

template <typename T>
class Node{
	public:
		T data;
		Node<T> *link;

		Node(T element){
		  data = element;
		  link = 0;
		}
	};

template <typename T>
class LinkedList{
	protected:
		Node<T> *first;
		int current_size;
	public:
		LinkedList(){
			first = 0;
			current_size = 0;
		};

		int GetSize(){
			return current_size;
		};

		void Insert(T element);
		
		virtual bool Delete(T &element);

		void Print();
};

template <typename T>
void LinkedList<T>::Insert(T element){

	Node<T> *newnode = new Node<T>(element);
	newnode -> link = first;
	first = newnode;
	current_size++;
}

template <typename T>
bool LinkedList<T>::Delete(T &element){

	if (first == 0)
		return false;
	
	Node<T> *current = first;
	Node<T> *previous = 0;
	
	while(1){
		if (current->link == 0){ 
			if (previous)
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;
	current_size--;

	return true;
}

template <typename T>
void LinkedList<T>::Print(){
	Node<T> *i;
	int index = 1;

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data << "]";
			}
			
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}


#endif
