#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    stack<string> st;

    string option;

    cin >> option;

    while(option != "KONIEC"){
        st.push(option);
        cin >> option;

    }
    
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
