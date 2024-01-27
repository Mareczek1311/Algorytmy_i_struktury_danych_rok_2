#include <iostream>

using namespace std;

void sort(vector<int> &arr, int idx){
    
    while(idx>0){
        if(arr[idx] < arr[idx-1]){
            cout << "SWAPPED: " << arr[idx] << " " << arr[idx-1]<< endl;
            swap(arr[idx], arr[idx-1]);
            sort(arr, idx-1);
        }
        idx--;
    }

}

int main(){
    vector<int> arr;
    

    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(6);

    sort(arr, arr.size()-1);
 
    for(int i =0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
