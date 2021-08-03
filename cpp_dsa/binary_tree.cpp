#include <cstdio>
#include <iostream>
using namespace std;

class Node {
  public:
    Node* left;
    Node* right;
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

    void p_add(Node* root, int val){
        if (!root->left){
          Node* new_root = new Node();
          new_root->value = val;
          root->left = new_root;
          return;
        }
        if (root->left && !root->right){
          Node* new_root = new Node();
          new_root->value = val;
          root->right = new_root;
          return;
        }
        p_add(root->left, val);
        p_add(root->right, val);
    }

    void p_display(Node* root){
      if (!root){
        return;
      }
      cout << "value is: " << root->value << endl;
        p_display(root->left);
        p_display(root->right);
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
        Node* new_node = new Node();
        new_node->value = val;
        root = new_node;
        return;
      }
      p_add(root, val);
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