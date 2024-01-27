#include <iostream>

using namespace std;

int fib_it(int n){
    if(n == 0){
        return 1;
    }
    int res = 1;

    for(int i = 2; i<n; i++){
        res *= i;
    }

    return res;
}

int fib_rec(int n){
    if(n == 1){
        return 1;
    }
    if(n == 0){
        return 0;
    }


    return fib_rec(n -1) + fib_rec(n-2);
}

int main(){
    cout << fib_it(3) << endl;
    cout << fib_rec(3) << endl;

    return 0;
}
