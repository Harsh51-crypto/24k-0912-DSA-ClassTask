#include <iostream>
using namespace std;

class Node
{

public:
   Node *next;
   string book;

   Node()
   {
      next = NULL;
      book = "";
   }

   Node(string name) : book(name)
   {
      next = NULL;
   }
};

class LL
{
public:
   Node *head;
   Node *tail;

   LL()
   {
      head = NULL;
      tail = NULL;
   }
   void insertAtTail(string name)
   {

      Node *temp = new Node(name);

      if (tail != NULL)
      {

         tail->next = temp;
         tail = temp;
      }
      else
      {
         tail = temp;
         head = temp;
      }
   }

   void insertAtHead(string name)
   {
      Node *temp = new Node(name);

      if (head != NULL)
      {
         temp->next = head;
         head = temp;
      }
      else
      {

         head = temp;
         tail = temp;
      }
   }

   bool search(string target)
   {

      Node *temp = head;
      while (temp != NULL)
      {
         if (temp->book == target)
            return true;
         temp = temp->next;
      }
      return false;
   }

   void insertAtPos(string target, string name)
   {

      Node *temp = head;
      Node *insert = new Node(name);

      while (temp != NULL)
      {

         if (temp->book == target)
         {
            insert->next = temp->next;
            temp->next = insert;
            return;
         }
         temp = temp->next;
      }
   }

   void print()
   {

      Node *temp = head;

      while (temp != NULL)
      {
         cout << temp->book << endl;
         temp = temp->next;
      }
   }
};

int main()
{
   LL l;
   l.insertAtTail("Data Structure");
   l.insertAtTail("Operating System");
   l.insertAtTail("Computer Networks");
   l.insertAtTail("Database System");

   l.print();
   cout << endl;

   l.insertAtHead("Artifical Intelligence");
   l.print();

   cout << endl;
   l.insertAtTail("Machine Learning");

   l.print();
   cout << endl;

   l.insertAtPos("Operating System", "Cyber Security");
   l.print();
   cout << endl;
   return 0;
}