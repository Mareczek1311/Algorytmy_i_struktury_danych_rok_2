#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int liczba;
    char option;

    queue<int> q;

    while(option != 'x'){
        switch(option){
            case 'e':
                cin >> liczba;
                q.push(liczba);
                break;
            case 'd':
                if(!q.empty()){
                    cout << q.front() << " ";
                    q.pop();
                }
                else{
                    cout << "! ";
                }
                break;
        }
        cin >> option;
    }

    return 0;
}
