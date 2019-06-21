#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
   //head initially is a null pointer
   head = nullptr;
   tail = nullptr;

   //size of list is 0
   listSize = 0;
}

LinkedList::~LinkedList(){

   tail = nullptr;
   clear();
}

//returns the size of the list
int LinkedList::size()
{
   return listSize;
}

//This function deletes the does
void LinkedList::deleteNode(Node* node)
{
    //checks to see if we have reached the end
    if (node==nullptr)
    {
       //if we have, sets the head to null
       head=nullptr;
    } else {

       //otherwise gets the pointer to the next node
       Node* nextNode = node->next;

       //deletes the current node
       delete node;

       //recursively moves to the next node
       deleteNode(nextNode);
    }
}

//The clear function operating recursively
void LinkedList::clear()
{
   //confirms that there are nodes in the list
   if (listSize!=0)
   {
      deleteNode(head);
      listSize=0;
   }
}

//adds a node at the nth(i) node
//Note that i must be greater than 0, or less than equal to
//the size of the linked list. Any variable outside of that
//range will have unpredictable results.
void LinkedList::addAt(int i, int data)
{
   //if the first node is requested
   if (i == 0)
      addFront(data);
   //if the back node is requested
   else if (i==(size()))
      addBack(data);
   else {

      //otherwise gets the node before the requested node
      Node* node = getNode(i);
      
      //creates a new node with a pointer to the next node
      //from the retrieved node
      Node* newNode = new Node(data, node->next);

      //increases the list size by 1
      ++listSize;

      //changes the pointer of the retrieved node to the new node
      node->next = newNode;
   }
}

//removes the nth(i) node
//Note that i must be greater than 0, or less than equal to
//the size of the linked list. Any variable outside of that
//range will have unpredictable results.
void LinkedList::deleteAt(int i)
{

   //if the first node is requested
   if (i==0)
     removeFront();

   //if the last node is requested (due to the need for the back pointer)
   else if(i==(size()-1))
     removeBack();
   else {
     //retrive the node prior to this selected node
     Node* node = getNode(i);

     //get the node to be deleted
     Node* deleteNode = node->next;

     //sets the pointer to the node after the node to be deleted
     node->next = deleteNode->next;

     //decreases the list size by 1
     --listSize;

     //deletes the node
     delete deleteNode;
   }

}

//private method to get the node at the nth(i) position
Node* LinkedList::getNode(int i)
{

   //sets up the search variables
   bool found = false;
   int count = 0;
   Node* counter = head;

   //iterates through the list
   while(!found)
   {
      //if the node is equal to 1 less than the request
      if(count == (i-1))
      {
         //raises the found flag
         found = true;
      } else {
         
         //otherwise gets the next node
         count++;
         counter = counter->next;
      }
   }

   return counter;
}

//gets the data from the nth (i) node
//Note that i must be greater than 0, or less than equal to
//the size of the linked list. Any variable outside of that
//range will have unpredictable results.
int LinkedList::get(int i)
{
   //if the contents of the first node is requested
   if(i==0)
   {
      i = head->data;

   } else {

      //otherwise gets the node before the requested node
      Node* counter = getNode(i);

      //retrieves the data from the requested node
      i = counter->next->data;
   }
  
  return i;
}

void LinkedList::addFront(int data)
{

   //create a new node and the node points to the head
   Node* node = new Node(data,head);

   //The head now points to this node.
   head = node;

   //if the tail points to null, then this will be the first node
   //so the tail will point to this node
   if(tail == nullptr)
     tail = node;

   //the size of the list is increased by one
   listSize++;

}

//recurseive function
void LinkedList::add(Node* newNode, Node* next)
{
   //checks to see if the next node is null (we are at the end)
   if(next->next == nullptr)
   {

      //if so, add the new node to the end
      next->next = newNode;

      //pointer for the new node has been set
      newNode->next = nullptr;
      tail=newNode;

   } else {
      //otherwise recursively moved to the next node
      add(newNode,next->next);
   }
}

//Recursive function to add a node to the end of the list
void LinkedList::addBack(int data)
{
   //create a new node with the data and nullptr
   Node* node = new Node(data,nullptr);

   add(node,head);

   //increases the size of the list
   listSize++;
}

void LinkedList::removeFront()
{
	//checks to see if the size of the list is greater than 0
	//and executes the function if it is
	if(size()>0)
	{
    	//creates a temporary pointer
	    Node* node = head;

	    //shifts the head to the next in line
	    head = head->next;

	    //deletes the previous head
	    delete node;

	    //decreases the size of the list by one.
	    listSize--;
	}
}

void LinkedList::remove(Node* node){
  
  if(node->next == tail) {
     delete tail;
     node->next = nullptr;
  } else {
     remove(node->next);
  }
}

void LinkedList::removeBack()
{
	//checks to see if the size of the list is greater than 0, and executes the function
	//if it is
	if(size()>0)
	{
       remove(head);
	
	   //decreases the size of the list by one
	   listSize--;
	}
}
