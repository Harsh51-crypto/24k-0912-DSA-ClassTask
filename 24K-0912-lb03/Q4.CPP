#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;

   Node(int data) : data(data)
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

   void insertAtHead(Node *&head, int data)
   {
      Node *temp = new Node(data);

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

   void insertAtTail(int data)
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
         cout << temp->data << " ";
         temp = temp->next;
      }
   }

   int getlen()
   {

      int len = 0;
      Node *temp = head;
      while (temp != NULL)
      {
         len++;
         temp = temp->next;
      }
      return len;
   }

   void sort()
   {

      int size = getlen();
      Node *temp = head;
      ;

      int count = 0;

      while (count < size - 1)
      {

         for (int i = 0; i < size && temp != NULL; ++i)
         {
            if (temp->next != NULL)
            {
               if ((temp->data) > (temp->next->data))
               {
                  int val = temp->data;
                  temp->data = temp->next->data;
                  temp->next->data = val;
               }
               temp = temp->next;
            }
         }
         ++count;
         temp = head;
      }
   }

   void concat(LL l2)
   {

      tail->next = l2.head;
   }

   void removeDuplicate()
   {

      Node *i = head;

      while (i != NULL)
      {

         Node *prev = i, *current = i->next;

         while (prev != NULL && current != NULL)
         {

            if (current->data == i->data)
            {
               prev->next = current->next;
               delete current;
               current = prev->next;
            }
            else
            {
               prev = current;
               current = prev->next;
            }
         }
         i = i->next;
      }
   }

   void findmiddle()
   {
      Node *tort = head, *hare = head;

      while (hare != NULL && hare->next != NULL)
      {
         hare = hare->next;
         if (hare->next != NULL)
         {
            hare = hare->next;
         }
         tort = tort->next;
      }
      cout << "The middle Elemenet is: " << tort->data << endl;
   }

   void merge(LL l3)
   {

      Node *i = head, *j = l3.head;
      Node *dummy = new Node(0), *current = dummy;

      while (i != NULL && j != NULL)
      {

         if (i->data <= j->data)
         {
            current->next = i;
            current = current->next;
            i = i->next;
         }
         else if (j->data < i->data)
         {
            current->next = j;
            current = current->next;
            j = j->next;
         }
      }
      while (i != NULL)
      {
         current->next = i;
         i = i->next;
         current = current->next;
      }
      while (j != NULL)
      {
         current->next = j;
         j = j->next;
         current = current->next;
      }
   }
};

int main()
{
   LL l;

   l.insertAtTail(4);
   l.insertAtTail(2);
   l.insertAtTail(3);
   l.insertAtTail(5);
   l.insertAtTail(1);
   cout << "Before Sorting! " << endl;
   l.print();
   cout << endl;
   l.sort();
   cout << "After Sorting: " << endl;
   l.print();
   cout << endl;

   LL l2;
   l2.insertAtTail(8);
   l2.insertAtTail(7);
   l2.insertAtTail(1);
   l2.insertAtTail(3);
   l2.insertAtTail(1);
   cout << "Another Linked List: " << endl;
   l2.print();
   cout << endl;
   l.concat(l2);
   cout << "Concat of Linked List: " << endl;
   l.print();
   l.removeDuplicate();
   cout << endl
        << "Removing Duplicates: " << endl;
   l.print();

   cout << endl;
   l.findmiddle();

   LL l3;
   l3.insertAtTail(4);
   l3.insertAtTail(6);
   l3.insertAtTail(5);
   l3.sort();
   cout << "Another Linked List for Merging: " << endl;
   l3.print();

   l.merge(l3);
   cout << endl
        << "Merged Linked List: " << endl;
   l.print();
}