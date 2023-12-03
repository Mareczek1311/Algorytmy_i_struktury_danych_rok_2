#include <iostream>

using namespace std;

struct node{
    int value;
    node* prev;
};

struct queue{
    node* start;
    node* end;
};

void enqueue(queue* &q, int value){
    node* n = new node;
    n->value = value;
    n->prev = nullptr;

    if(q->end == nullptr){
        q->start = n;
        q->end = n;
    }
    else{
        q->end->prev = n;
        q->end = n;
    }
}

int dequeue(queue* &q){
    if(q->end == nullptr){
        return -1;
    }
    else if(q->end == q->start){
        int res;
        node* n = q->end;
        res = n->value;
        q->end = nullptr;
        q->start = nullptr;
        delete n;
        return res;
    }
    else{
        int res;
        node* n = q->start;
        res = n->value;
        q->start = q->start->prev;
        delete n;
        return res;
    }
}

int main(){
    queue* q = new queue;

    q->start = nullptr;
    q->end = nullptr;

    char option;
    int val;
    int returned;
    cin >> option;

    while(option != 'x'){
        switch(option){
            case 'e':
                cin >> val;
                enqueue(q, val);
                break;
            case 'd':
                returned = dequeue(q);
                if(returned == -1){
                    cout << "! ";
                } 
                else{
                    cout << returned << " ";
                }
                break;
        
        }
        cin >> option;

    }

    delete q;

    return 0;
}