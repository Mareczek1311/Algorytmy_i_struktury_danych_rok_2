#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int>& arr, int liczba){

    arr.push_back(liczba);
    int childIdx = arr.size() - 1;
    int idx = (childIdx-1) / 2;


    while(idx >= 0){
        if(arr[idx] > arr[childIdx]){
            swap(arr[idx], arr[childIdx]);
            childIdx = idx;
            idx = (idx-1)/2;
        }
        else{
            break;
        }
    }


}

int getMax(vector<int>& arr){

    int max = arr[0];

    if(arr.size() == 1){
        arr.pop_back();
        return max;
    }

    int idx = 0;
    swap(arr[0], arr[arr.size()-1]);

    arr.pop_back();


    while(idx < arr.size()-1){
        if (2 * idx + 2 <= arr.size() - 1 && arr[2 * idx + 1] > arr[2 * idx + 2]) {
            if (arr[2 * idx + 2] <= arr[idx]) {
                swap(arr[2 * idx + 2], arr[idx]);
                idx = 2 * idx + 2;
            }
        } else {
            if (2 * idx + 1 <= arr.size() - 1 && arr[2 * idx + 1] < arr[idx]) {
                swap(arr[2 * idx + 1], arr[idx]);
                idx = 2 * idx + 1;
            } else {
                break;
            }
        }
    }


    return max;
}

int main() {

    vector<int> heap;

    int n;
    int liczba;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> liczba;
        insert(heap, liczba);
    }

    while(!heap.empty()){
        cout << getMax(heap) << " ";
    }

    return 0;
}
