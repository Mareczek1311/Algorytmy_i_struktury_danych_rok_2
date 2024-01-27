#include <iostream>
#include <vector>

using namespace std;

void ins_it(vector<int>& arr){
    for(int i=1; i<arr.size(); i++){
        int j = i-1;
        while(j>=0 && arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
            j--;
        }
    }
}

void ins_rec(vector<int>& arr, int n){
    if(n == 0){
        return;
    }

    ins_rec(arr, n-1);

    while( n>0  && arr[n] < arr[n-1]){
        swap(arr[n], arr[n-1]);
        n--;
    }

}

int main(){
    int n;
    vector<int> arr;
    cin >> n;
    int liczba;
    for(int i=0; i<n; i++){
        cin >> liczba;
        arr.push_back(liczba);
    }
    
    ins_rec(arr, arr.size()-1);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " " ;
    }

    cout << endl;

    return 0;
}
