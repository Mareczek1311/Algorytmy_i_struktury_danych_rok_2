//nullptr nie dziala
//NULL instead

#include <iostream>

using namespace std;

struct node{
    int val;
    node* next;
    node* prev;
};

struct list{
    node* start;
    node* curr;
};


void insert(list *& l, int val){
    node* newNode = new node;
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(l->start == NULL){
        l->start = newNode;
        l->curr = newNode;
    }
    else{
        if(l->curr->next == NULL){
            l->curr->next = newNode;
            newNode->prev = l->curr;
        }
        else{
            newNode->prev = l->curr;
            newNode->next = l->curr->next;
            l->curr->next->prev = newNode;
            l->curr->next = newNode;

        }
        l->curr = l->curr->next;
    }
}

void del(list *& l){
    node* deletedNode = l->curr;

    if(l->start == l->curr){
        l->start = NULL;
        l->curr = NULL;
    }
    else{
        if(l->curr->next == NULL){
            l->curr = l->curr->prev;
        }
        else{
            l->curr = l->curr->prev;
            l->curr->next = deletedNode->next;
            deletedNode->next->prev = l->curr;
        }
    }

    delete deletedNode;
}

void search(list *& l, int n){
    int currInx = 1;
    node* currNode = l->start;

    while(currInx < n){
        currNode = currNode->next;
        currInx++;
    }

    l->curr = currNode;
}

int main() {

    char opt;
    int num;
    list* l = new list;

    l->start = NULL;
    l->curr = NULL;

    cin >> opt;
    while(opt != 'x'){
        switch(opt){
            case 'i':
                cin >> num;
                insert(l, num);
                break;
            case 'd':
                del(l);
                break;
            case 's':
                cin >> num;
                search(l, num);
                break;
        }
        cin >> opt;
    }

    int start, curr;
    node* currNode = l->start;

    while(currNode){
        if(currNode == l->start){
            start = l->start->val;
        }
        if(currNode == l->curr){
            curr = l->curr->val;
        }
        cout << currNode->val << " ";
        currNode = currNode->next;
    }

    cout << "Poczatek: " << start << ", Biezacy: " << curr << endl;

    while(l->start != l->curr){
        l->start = l->start->next;
        delete l->start->prev;
    }
    delete l->start;

    delete l;

    return 0;
}
