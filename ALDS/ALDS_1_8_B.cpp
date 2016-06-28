#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node{
  int key;
  Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int k){
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while( x != NIL){
    y = x;
    if( z->key < x->key){
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if(y == NIL){
    root = z;
  } else {
    if (z->key < y->key){
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

bool isExist(int k, Node *x){
  if (x == NIL) return false;
  if(x->key == k) return true;
  else if(k < x->key) isExist(k, x->left);
  else isExist(k, x->right);
}


void inorder(Node *u){
  if (u == NIL) return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node *u){
  if (u == NIL) return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}



int main() {
    ios::sync_with_stdio(false);

    int n, x;
    string com;
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> com;
      if(com == "insert"){
        cin >> x;
        insert(x);
      } else if (com == "find") {
        cin >> x;
        isExist(x, root) ? cout << "yes\n" : cout << "no\n";
      } else if (com == "print"){
        inorder(root);
        cout << "\n";
        preorder(root);
        cout << "\n";
      }
    }
    return 0;
}
