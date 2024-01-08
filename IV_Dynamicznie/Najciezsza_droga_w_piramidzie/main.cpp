#include <iostream>

using namespace std;

int rec(int arr[], int lvl, int maxlvl, int sum, int currinx){
    if(lvl == maxlvl){
        return sum;
    }

    return max(rec(arr, lvl+1, maxlvl, sum + arr[currinx+0+lvl],currinx+0 + lvl),rec(arr, lvl+1, maxlvl, sum + arr[currinx+1 + lvl],currinx+1 + lvl));
}

int main() {
    int n;
    cin >> n;
    int size = 0;
    int mxl = 0;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int i=1;
    while(size<n){
        size += i;
        mxl += 1;
        i++;
    }

    cout << rec(arr, 1, mxl, arr[0] ,0);

    return 0;
}
