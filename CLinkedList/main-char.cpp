#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class CLinkedList;

class Node{
  friend class CLinkedList;
  
  char* data;
  Node* next;

public:
  Node(const char* inData, Node* inNext = NULL):
    data(new char[strlen(inData)+1]),
    next(inNext)
  {
    strcpy(data, inData);
  }

  ~Node(){
    delete [] data;
  }

  void setData(const char* inData){
    delete [] data;
    data = new char[strlen(inData)+1];
    strcpy(data, inData);
  }

  void setNext(Node* inNext){
    next = inNext;
  }

  const char* getData() const{
    return data;
  }

  Node* getNext() const{
    return next;
  }
};

class CLinkedList{

//  friend class Node;
 
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

  void insertBackNode(const char* inData){
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
    if(read == write){
      delete read;
      read = NULL;
      write = NULL;
    }
  }

  void printElems() const{
    if(read != NULL){
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

  clist.insertBackNode("a");
  clist.insertBackNode("b");
  clist.insertBackNode("c");
  clist.insertBackNode("d");
  clist.insertBackNode("e");

  clist.printElems();

  clist.removeFrontNode();
  clist.removeFrontNode();
  clist.printElems();

  clist.insertBackNode("f");
  clist.printElems();

  clist.removeFrontNode();
  clist.removeFrontNode();
  clist.removeFrontNode();
  clist.removeFrontNode();
  clist.printElems();

  clist.removeFrontNode();
  clist.printElems();

  clist.insertBackNode("g");
  clist.printElems();
}
