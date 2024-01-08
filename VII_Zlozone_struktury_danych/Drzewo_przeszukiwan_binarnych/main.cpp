#include <iostream>

using namespace std;

struct node{
    int value;
    node* left;
    node* right;

};
void preorder(node* n) {
    if (n == NULL) {
        return;
    }
    cout << n->value << " ";
    preorder(n->left);
    preorder(n->right);
}

void inorder(node* n) {
    if (n == NULL) {
        return;
    }
    inorder(n->left);
    cout << n->value << " ";
    inorder(n->right);
}

void postorder(node* n) {
    if (n == NULL) {
        return;
    }
    postorder(n->left);
    postorder(n->right);
    cout << n->value << " ";
}
node* insert(node* n, node* newN){
    if(n==NULL){
        return newN;
    }

    if (n->value < newN->value) {
        n->right = insert(n->right, newN);
    }
    else {
        n->left = insert(n->left, newN);
    }

    return n;
}

void delete_Tree(node* root){
    if(root == nullptr){
        return;
    }

    delete_Tree(root->left);
    delete_Tree(root->right);

    delete root;
}

int main() {
    //prawo >=
    node* root = NULL;
    int liczba = -1;
    cin >> liczba;
    while(liczba != -999){

        node* newNode = new node;
        newNode->value = liczba;
        newNode->left = NULL;
        newNode->right = NULL;

        root = insert(root, newNode);

        cin >> liczba;
    }

    inorder(root);

    cout << endl;
    preorder(root);

    cout << endl;
    postorder(root);

    delete_Tree(root);

    return 0;
}
