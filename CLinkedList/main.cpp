#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class CLinkedList;

class Node{
  friend class CLinkedList;
  
  int data;
  Node* next;

public:
  Node(int inData, Node* inNext = NULL):
    data(inData),
    next(inNext)
  {
  }

  ~Node(){
  }

  void setData(int inData){
    data = inData;
  }

  void setNext(Node* inNext){
    next = inNext;
  }

  int getData() const{
    return data;
  }

  Node* getNext() const{
    return next;
  }
};

class CLinkedList{

  Node* read;
  Node* write;

public:
  CLinkedList():
    read(NULL),
    write(NULL)
  {}

  ~CLinkedList(){
    Node* temp = read;
    while(temp != write){
      read = read->next;
      delete temp;
      temp = read;
      write->next = read;
    }
  }

  void insertBackNode(int inData){
    Node* node = new Node(inData);
    if(write == NULL){
      //list is empty
      read = node;
      write = node;
    }
    else{
      write->next = node;
      write = node;
      write->next = read;
    }
  }

  void removeFrontNode(){
    if(read != NULL && read != write){
      //list is not empty
      Node* temp = read;
      read = read->next;
      delete temp;
      write->next = read;
    }
    else if(read == write){
      delete read;
      read = NULL;
      write = NULL;
    }
  }

  void printElems() const{
    if(read != NULL){
      //List is not empty
      Node* temp = read;
      cout << "Elemets are " << endl;
      do{
        cout << temp->data << " ";
        temp = temp->next;
      }while(temp != write->next);
      cout << endl;
    }
    else{
      cout << "List is empty. Can't print" << endl;
    }
  }
};

int main(){
 
  CLinkedList clist;

  clist.insertBackNode(10);
  clist.insertBackNode(20);
  clist.insertBackNode(30);
  clist.insertBackNode(40);
  clist.insertBackNode(50);

  clist.printElems();

  clist.removeFrontNode();
  clist.removeFrontNode();
  clist.printElems();

  clist.insertBackNode(60);
  clist.printElems();

  clist.removeFrontNode();
  clist.removeFrontNode();
  clist.removeFrontNode();
  clist.removeFrontNode();
  clist.printElems();

  clist.removeFrontNode();
  clist.printElems();

  clist.insertBackNode(70);
  clist.printElems();
}
