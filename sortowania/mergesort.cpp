#include <iostream>
#include<vector>

using namespace std;

void merge(vector<int>& arr, int s, int mid, int e){
    

    vector<int> left;
    vector<int> right;

    for(int i=s; i<=mid; i++){
        left.push_back(arr[i]);
    }

    for(int i=mid+1; i<=e; i++){
        right.push_back(arr[i]);
    }

    int lptr = 0, rptr = 0;

    while(lptr<left.size() && rptr < right.size()){
        if(left[lptr] < right[rptr]){
            arr[s] =left[lptr];
            s++;
            lptr++;
        }
        else{
            arr[s] = right[rptr];
            s++;
            rptr++;
        }
    }

    while(lptr<left.size()){
        arr[s] = left[lptr];
        s++;
        lptr++;
    }

    while(rptr<right.size()){
        arr[s] = right[rptr];
        s++;
        rptr++;
    }



}

void mergeSort(vector<int>&arr, int s, int e){
    if((e-s)+1<=1){
        return;
    }

    int mid = (e+s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr,s, mid,e);

}

int main(){
   int n;
   cin >> n;

   
   vector<int> arr;

    int liczba;

    for(int i=0; i<n; i++){
        cin >> liczba;
        arr.push_back(liczba);
    }

    mergeSort(arr, 0, arr.size()-1);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
