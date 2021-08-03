#include <cstdio>
#include <iostream>
using namespace std;

class Node {
  public:
  int value;
  Node* next;
};

class LinkedList {
  private:
  Node* head;

  public:
  LinkedList(){
    head = NULL;
  }
  ~LinkedList(){cout << "Deleting LinkedList" << endl;};
  void insert(int value){
    Node* new_node = new Node();
    new_node->value = value;
    new_node->next = head;
    head = new_node;
  }
  void display(){
    if (head == NULL){
      cout << "The Linked List is Empty!!" << endl;
    }
    Node* current = head;
    while (current){
      cout << current->value << endl;
      current = current->next;
    }
  }
  void reverse(){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr){
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }
};

struct Element {
  Element* next{};
  void insert_after(Element* new_element){
    new_element->next = next;
    next = new_element;
  }
  char prefix[2];
  short operating_number;
};

int main(){

  LinkedList* ll = new LinkedList();
  ll->insert(55);
  ll->insert(66);
  ll->insert(77);
  ll->display();
  ll->reverse();
  ll->display();
  delete ll;

  Element trooper1, trooper2, trooper3;
  trooper1.prefix[0] = 'T';
  trooper1.prefix[1] = 'K';
  trooper1.operating_number = 421;
  trooper1.insert_after(&trooper2);
  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;
  trooper2.insert_after(&trooper3);
  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;

  for (Element *cursor = &trooper1; cursor; cursor = cursor->next){
    printf("stormtrooper %c%c-%d\n", 
      cursor->prefix[0],
      cursor->prefix[1],
      cursor->operating_number);
  }
}