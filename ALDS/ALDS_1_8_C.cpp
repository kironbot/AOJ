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

Node * find(Node *u, int k){
  while(u != NIL && k != u->key){
    if(k < u->key) u = u->left;
    else u = u->right;
  }
  return u;
}

Node * getMinimum(Node *x){
  while( x->left != NIL){
    x = x->left;
  }
  return x;
}

Node * getSuccessor(Node *x){
  if (x->right != NIL) return getMinimum(x->right);
  Node *y = x->parent;
  while (y != NIL && x == y->right){
    x = y;
    y = y->parent;
  }
  return y;
}

void deleteTree(Node *z){
  Node *y;
  Node *x;
  if(z->left == NIL || z->right == NIL) y = z;
  else y = getSuccessor(z);

  if(y->left != NIL) x = y->left;
  else x = y->right;

  if(x != NIL) x->parent = y->parent;
  if(y->parent == NIL) root = x;
  else if (y == y->parent->left) y->parent->left = x;
  else y->parent->right = x;

  if(y != z) z->key = y->key;
  free(y);
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
      } else if(com == "delete") {
        cin >> x;
        deleteTree(find(root, x));
      } else if (com == "print"){
        inorder(root);
        cout << "\n";
        preorder(root);
        cout << "\n";
      }
    }
    return 0;
}
