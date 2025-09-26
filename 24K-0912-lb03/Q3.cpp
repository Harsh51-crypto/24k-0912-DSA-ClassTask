#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;

		Node(int value){
			data = value;
			prev = NULL;
			next = NULL;
		}
};

class DoublyList{
	private:
		Node* head;
		Node* tail;

	public:
		DoublyList(){
			head = NULL;
			tail = NULL;
		}

		void insertAtEnd(int value){
			Node* newNode = new Node(value);
			if(head == NULL){
				head = newNode;
				tail = newNode;
			} 
			else{
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
		}

		void deleteAtFront(){
			if(head == NULL){
				cout<<"List is empty"<<endl;
				return;
			}
			Node* temp = head;
			if(head == tail){
				head = NULL;
				tail = NULL;
			} 
			else{
				head = head->next;
				head->prev = NULL;
			}	delete temp;
		}

		int search(int value){
			Node* current = head;
			while(current != NULL){
				if(current->data == value){
					return 1;
				}   current = current->next;
			}       return 0;
		}

		void display(){
			Node* current = head;
			while(current != NULL){
				cout<<current->data<<" ";
				current = current->next;
			}
			cout<<endl;
		}
};

int main(){
	DoublyList l;

	l.insertAtEnd(10);
	l.insertAtEnd(20);
	l.insertAtEnd(30);

	cout<<"List: ";
	l.display();

	l.deleteAtFront();
	cout<<"After deleting front: ";
	l.display();

	if(l.search(20)){
		cout<<"20 Found"<<endl;
	}
	else
		cout<<"20 Not Found"<<endl;

	if(l.search(40)){
		cout<<"40 Found"<<endl;
	}
	else
		cout<<"40 Not Found"<<endl;

}