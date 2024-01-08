#include <iostream>

using namespace std;

struct node{
    int value;
    node* left;
    node* right;
};

node* insert(node* root, node* newN){
    if(root == nullptr){
        return newN;
    }

    if(root->value < newN->value){
        root->right = insert(root->right, newN);
    }
    else{
        root->left = insert(root->left, newN);
    }

    return root;
}

void inorder(node* root){
    if(root == nullptr){
        return;
    }

    inorder(root->left);
    cout << root-> value << " ";
    inorder(root->right);
}

int findMin(node* root){
    node* curr = root;
    while(curr != nullptr && curr->left != nullptr){
        curr = curr->left;
    }
    return curr->value;
}

node* delete_node(node* root, int value){
    if(root == nullptr){
        return nullptr;
    }

    if(root->value == value){
        if(root->left == nullptr && root->right == nullptr){
            return nullptr;
        }
        if(root->left == nullptr && root->right != nullptr){
            return root->right;
        }
        if(root->left != nullptr && root->right == nullptr){
            return root->left;
        }
        if(root->left != nullptr && root->right != nullptr){
            root->value = findMin(root->right);
            delete_node(root->right, root->value);
        }
    }

    root->left = delete_node(root->left, value);
    root->right = delete_node(root->right, value);

    return root;
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

    node* root = nullptr;

    int liczba = -1;

    cin >> liczba;

    while(liczba != -999){

        node* newNode = new node;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->value = liczba;
        root = insert(root, newNode);

        cin >> liczba;
    }

    liczba = -1;
    cin >> liczba;
    while(liczba != -999){
        delete_node(root, liczba);
        cin >> liczba;
    }

    inorder(root);
    delete_Tree(root);

    return 0;
}
