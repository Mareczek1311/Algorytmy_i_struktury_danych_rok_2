#include <iostream>

using namespace std;

int main(){

    int n;

    cin >> n;

    int arr[n+1];
    arr[0] = 0;
    for(int i=1; i<n+1; i++){
        cin >> arr[i];
    }
    
    for(int i=2;i<=n;i++){
        arr[i] = max(arr[i-1], arr[i] + arr[i-2]);
    }
   
    cout << arr[n] << endl;

    return 0;
}
