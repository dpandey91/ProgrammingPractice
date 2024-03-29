#include <iostream>

using std::cout;
using std::endl;

class Node{
  int data;
  Node* next;

public:
  Node(int inData, Node* inNext = NULL):
    data(inData),
    next(inNext)
  {}
  
  ~Node(){}
  
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

class SLinkedList{
  Node* head;
  Node* tail;

public:
  SLinkedList():
    head(NULL),
    tail(NULL)
  {}
  
  ~SLinkedList(){
    Node* temp = head;
    while(temp != NULL){
      head = head->getNext();
      delete temp;
      temp = head;
    }
  }
  
  void insertBackNode(int inData){
    Node* node = new Node(inData);
    if(head == NULL){
      //List is empty
      head = node;
      tail = node;
    }
    else{
      tail->setNext(node);
      tail = node;
    }
  }

  void insertFrontNode(int inData){
    Node* node = new Node(inData);
    if(head == NULL){
      //List is empty
      head = node;
      tail = node;
    }
    else{
      node->setNext(head);
      head = node;
    }
  }

  void removeBackNode(){
    if(head != NULL && head != tail){
      Node* temp = head;
      while(temp->getNext()->getNext() != NULL){
        temp = temp->getNext();
      }
      delete tail;
      tail = temp;
      tail->setNext(NULL);
    }
    else if(head == tail){
      delete head;
      head = NULL;
      tail = NULL;
    }
  }

  void removeFrontNode(){
    if(head != NULL && head != tail){
      Node* temp = head;
      head = head->getNext();
      delete temp;
    }
    else if(head == tail){
      delete head;
      head = NULL;
      tail = NULL;
    }
    //Now if the list is empty
    if(head == NULL)
      tail = NULL;
  }

  void printElems() const{
    Node* temp = head;
    cout << "Elements are:" << endl;
    while(temp != NULL){
      cout << temp->getData() << " ";
      temp = temp->getNext();
    }
    cout << endl;
  }
};

int main(){

  //TestProgram

  SLinkedList slist;

  slist.insertBackNode(10);
  slist.insertBackNode(20);
  slist.insertBackNode(30);
  slist.insertFrontNode(40);
  slist.insertFrontNode(50);
  slist.insertFrontNode(60);

  slist.printElems();

  slist.removeFrontNode();
  slist.printElems();

  slist.removeBackNode();
  slist.printElems();

  slist.removeBackNode();
  slist.removeBackNode();
  slist.removeBackNode();
  slist.printElems();

  slist.removeBackNode();
  slist.printElems();

  slist.insertFrontNode(70);
  slist.insertFrontNode(80);
  slist.printElems();

  return 0;
}
