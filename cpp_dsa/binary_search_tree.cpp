#include <cstdio>
#include <iostream>
using namespace std;

class Node {
  public:
    Node* left{NULL};
    Node* right{NULL};
    int value;
};

class BinaryTree {
  private:

    Node* root;

    void p_destroy(Node* root){
      if(root){
        cout << "deleting: " << root->value << endl;
        p_destroy(root->left);
        p_destroy(root->right);
        delete root;
      }
    }

    Node* new_node(int val){
      Node* new_root = new Node();
      new_root->value = val;
      return new_root;
    }

    void p_add(Node* root, int val){
      if (val < root->value){
        if (root->left) p_add(root->left, val);
        else root->left = new_node(val);
      }
      else {
        if (root->right) p_add(root->right, val);
        else root->right = new_node(val);
      }
    }

    void p_display(Node* root){
      if (root){
        cout << "value is: " << root->value << endl;
        p_display(root->left);
        p_display(root->right);
      }
    }

  public:
    BinaryTree(){
      root = NULL;
    }

    ~BinaryTree(){
      p_destroy(root);
    }

    void add(int val){
      if (!root){
        root = new_node(val);
      }
      else {
        p_add(root, val);
      }
    }

    void display(){
      p_display(root);
    }
};

int main(){
  BinaryTree* bt = new BinaryTree();
  bt->add(1);
  bt->add(2);
  bt->add(33);
  bt->add(55);
  bt->add(77);
  bt->add(99);
  bt->display();
  delete bt;
};