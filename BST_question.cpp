#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
struct node{
    char value;
    node *left;
    node *right;
};
node* createnode(node *p,char c);
void inorder(node *p);
void preorder(node *p);
void postorder(node *p);

int main()
{
    node *p=NULL;
    string s="5372468";
    for(int i=0;i<s.length();i++){
         p=createnode(p,s[i]);
    }
    cout << "inorder  :";
    inorder(p);
    cout << endl;
    cout << "preorder :";
    preorder(p);
    cout << endl;
    cout << "postorder:";
     postorder(p);
    cout << endl;
    return 0;
}

node* createnode(node *p,char c){
    // make a new node
    node* newNode = new node();
    // initialize
    newNode->value = c;
    newNode->left = NULL;
    newNode->right = NULL;

    // if the tree not empty
    if(!p) return newNode;
    // if the tree is not empty
    node* treeRoot = p;
    while(p) {
        if(c > p->value) {
            if(p->right == NULL)
                {p->right = newNode;break;}
            p = p->right;
        } else {
            if(p->left == NULL)
                {p->left = newNode;break;}
            p = p->left;
        }
    }
    return treeRoot;
}

void inorder(node *p){//left root right
    if(!p) return;
    inorder(p->left);
    cout << p->value;
    inorder(p->right);
}

void preorder(node *p){//root left right
    if(!p) return;
    cout << p->value;
    preorder(p->left);
    preorder(p->right);
}

void postorder(node *p){//left right root
    if(!p) return;
    postorder(p->left);
    postorder(p->right);
    cout << p->value;
}
