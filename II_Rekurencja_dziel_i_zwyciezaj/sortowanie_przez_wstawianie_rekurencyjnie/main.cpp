#include <iostream>

using namespace std;

void insertion_sort(int* &arr, int n){
    if(n<=1){
        return;
    }

    insertion_sort(arr, n-1);
    int j=n-2;

    while(j>=0 && arr[j+1] < arr[j]){
        swap(arr[j+1], arr[j]);
        j--;
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    insertion_sort(arr, n);

    for(int i=0; i<n-1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[n-1];

    delete[] arr;
    return 0;
}
