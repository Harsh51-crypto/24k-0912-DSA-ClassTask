#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
   string song;
   Node *next;

   Node(string data) : song(data)
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

   void insertAtHead(string data)
   {
      Node *temp = new Node(data);

      if (head != NULL)
      {

         temp->next = head;
         head->next = temp;
         head = temp;
      }
      else
      {
         head = temp;
         temp->next = head;
         tail = temp;
      }
   }

   void insertAtTail(string data)
   {
      Node *temp = new Node(data);

      if (tail != NULL)
      {
         tail->next = temp;
         tail = temp;
         tail->next = head;
      }
      else
      {
         tail = temp;
         temp->next = tail;
         head = tail;
      }
   }

   void print(Node *&head)
   {
      Node *temp = head;

      do
      {
         cout << temp->song << " ";
         temp = temp->next;
      } while (temp != NULL);
   }
};

int main()
{
}