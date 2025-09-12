#include<iostream>
using namespace std;

class Node{

    public:
    Node *next;
    string book;


    Node(){
        next=NULL;
        book="";
    }

    Node(string name):book(name){
        next=NULL;
    }

};

class LL
{


    Node *head;
    Node *tail;
public:

void insertAtTail(string name){

    Node *temp=new Node(name);

    if(tail!=NULL){
        
        tail->next=temp;
         tail=temp;
        
    }
    else {
        tail=temp;
    }
}

void insertAtHead(string name){
    Node *temp=new Node(name);

    if(head!=NULL){
        temp->next=head;
        head=temp;
    }
    else{

        head=temp;
    }



}

void insertAtPos(string target,string name){


    Node *temp=head;
        Node *insert=new Node(name);
        
    while(temp!=NULL){

        if(temp->book==target) {
            
        }
    }

}




};


int main(){



    return 0;
}