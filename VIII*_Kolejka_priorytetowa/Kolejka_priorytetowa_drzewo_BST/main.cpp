#include <iostream>

using namespace std;

struct node{
    int value;
    node* left;
    node* right;

    node(int value) : value(value){}
};

node* insert(node* root, int value){
    if(root == nullptr){
        node* curr = new node(value);
        return curr;
    }

    if(root->value < value){
        root->right = insert(root->right, value);
    }
    else{
        root->left = insert(root->left, value);
    }

    return root;

}
//tezeba znalezc maksimum a to proste
//trzeba usunac minimum

node* find_max(node* root){
    if(root == nullptr){
        return nullptr;
    }

    node* curr = root;

    while(curr->right != nullptr){
        curr = curr->right;

    }

    return curr;
}

node* extractMax(node* root, int& deletedValue) {
    if(!root) return nullptr;

    if(root->right) {
        root->right = extractMax(root->right, deletedValue);

        return root;
    } else {
        deletedValue = root->value;
        node *temp = root->left;
        delete root;
        return temp;

    }

}

int main() {

    node* root = nullptr;
    int num;
    char opcja;
    node* maxi;

    cin >> opcja;

    while(opcja != 'x'){

        switch(opcja){
            case 'i':
                cin >> num;
                root = insert(root, num);
                break;
            case 'e':

                maxi = find_max(root);

                if(maxi == nullptr){
                    cout << "! ";
                }
                else {
                    int deletedValue = -1;
                    root = extractMax(root, deletedValue);
                    cout << deletedValue << " ";
                }

        }

        cin >> opcja;

    }


    return 0;
}
