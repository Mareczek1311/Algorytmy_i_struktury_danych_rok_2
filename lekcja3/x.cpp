#include <iostream>

using namespace std;

int rec(int n, int x){
    if(n == 0){
        return 1;
    }
    
    x *= rec(n-1, x);
    return x;
}

int main(){

    cout << rec(2, 3);

    return 0;
}
