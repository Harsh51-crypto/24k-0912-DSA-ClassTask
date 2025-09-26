#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
   string title;
   Node *next;

   Node(string title) : title(title)
   {
      next = NULL;
   }
};

class LL
{

   Node *head;
   Node *tail;

public:
   LL()
   {
      head = NULL;
      tail = NULL;
   }

   void insertAtTail(string data)
   {
      Node *temp = new Node(data);

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

   void print()
   {
      Node *temp = head;
      while (temp != NULL)
      {
         cout << temp->title << endl;
         temp = temp->next;
      }
   }

   void deleteNode()
   {
      Node *temp = head;
      if (temp != NULL)
      {
         head = temp->next;
         delete temp;
      }
   }

   void search(string val)
   {
      bool flag = false;
      Node *temp = head;
      while (temp != NULL)
      {

         if (temp->title == val)
         {
            cout << temp->title << " Found! " << endl;
            flag = true;
            break;
         }
         temp = temp->next;
      }
      }

   void Pos(int pos)
   {

      int count = 0;
      Node *temp = head;
      while (temp != NULL)
      {

         if (count == pos)
         {
            cout << temp->title << " " << "Found At Positon: " << count << endl;
            return;
         }
         temp = temp->next;
      }
   }
};

int main()
{

   LL l;
   l.insertAtTail("Harry-Potter");
   l.insertAtTail("Atomic-Habits");
   l.insertAtTail("Rich-Dad");
   l.print();
   cout << endl;
   cout << "Inserting Book At end of Tail: " << endl;
   l.insertAtTail("Win-Friends");
   l.print();

   cout << endl;
   cout << "Deleting Book At Front! " << endl;
   l.deleteNode();
   l.print();

   
   string str;
   cout << "Enter the Name of Book You want To Search! " << endl;
   getline(cin, str);

   l.search(str);
}