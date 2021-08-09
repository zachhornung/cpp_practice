#include <cstdio>
#include <iostream>
using namespace std;

struct Element {
  Element* next;
  int data;
};

class Stack {
  private:
    Element* head;
  public:
    Stack();
    ~Stack();
    void push(int data);
    int pop();
    bool peek();
};

Stack::Stack(){
  head = NULL;
};

Stack::~Stack(){
  while(head){
    Element* next = head->next;
    delete head;
    head = next;
  };
  cout << "deleting stack" << endl;
};

void Stack::push(int data){
  Element* element = new Element;
  element->data = data;
  element->next = head;
  cout << "creating: " << element->data << endl;
  head = element;
  return;
};

int Stack::pop(){
  Element* popElement = head;
  if (!head) throw runtime_error( "stack is empty." );
  int data = head->data;
  head = head->next;
  delete popElement;
  return data;
};

bool Stack::peek(){
  return head != NULL;
};


int main(){
  Stack stack = Stack();
  stack.push(0);
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  while (stack.peek()){
    int popped = stack.pop();
    cout << "popping: "<< popped << endl;
  }
};
