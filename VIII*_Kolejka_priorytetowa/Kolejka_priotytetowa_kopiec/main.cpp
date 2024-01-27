#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int>& arr, int liczba){

    arr.push_back(liczba);
    int i = arr.size() - 1;

    while(i>1 && arr[i] > arr[i/2]){
        int tmp = arr[i];
        arr[i] = arr[i/2];
        arr[i/2] = tmp;
        i = i/2;
    }
}

int getMax(vector<int>& arr){
    if(arr.size() == 1){
        return -1;
    }
    if(arr.size() == 2){
        int res = arr[1];
        arr.pop_back();
        return res;
    }

    int res = arr[1];
    arr[1] = arr[arr.size()-1];
    arr.pop_back();

    int i = 1;

    while(2*i < arr.size()){
        if(2*i+1 < arr.size() && arr[2*i+1] > arr[2*i] && arr[i] && arr[i] < arr[2*i+1]){
            int tmp = arr[i];
            arr[i] = arr[2*i+1];
            arr[2*i+1] = tmp;
            i = 2*i+1;
        }
        else if(arr[i] < arr[2*i]){
            int tmp = arr[i];
            arr[i] = arr[2*i];
            arr[2*i] = tmp;
        }
        else{
            break;
        }
    }
    return res;
}

int main() {

    vector<int> heap;

    heap.push_back(0);

    char znak;
    int liczba;

    cin >> znak;

    while(znak != 'x'){

        switch(znak){
            case 'i':
                cin >> liczba;
                insert(heap, liczba);
                break;

            case 'e':
                if(heap.size() == 1){
                    cout << "!";
                }
                else {
                    cout << getMax(heap) << " ";
                }
                break;
        }

        cin >> znak;
    }

    return 0;
}
