#include <iostream>

using namespace std;

void quicksort(vector<vector<int> >& arr, int s, int e){
    if(e-s+1<=1){
        return;
    }

    int pivot = arr[e][1];
    int pointer = s;

    for(int i=s; i<e; i++){
        if(arr[i][1] < pivot){
            swap(arr[i], arr[pointer]);
            pointer++;
        }
    }
    swap(arr[e], arr[pointer]);

    quicksort(arr, s, pointer-1);
    quicksort(arr, pointer+1, e);

}

int main(){
    
    int n;
    cin >> n;

    vector<vector<int> > arr;
    vector<int> a;
    int liczba;
    for(int i=0; i < n; i++){
        arr.push_back(a);
        cin >> liczba;
        arr[i].push_back(liczba);

        cin >> liczba;
        arr[i].push_back(liczba);
    }
  
    quicksort(arr, 0, arr.size()-1);
    /*
    for(int i=0; i<arr.size(); i++){
        cout << arr[i][0] << " " << arr[i][1] << endl;
    }
    */
    
    if(n == 0){
        cout << "0" << endl;
    }
    else{
        int res = 1;
        int curr = 0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i][0] >= arr[curr][1]){
                res++;
                curr = i;
            }
        }
        cout << res << endl;

    }



    return 0;
}
