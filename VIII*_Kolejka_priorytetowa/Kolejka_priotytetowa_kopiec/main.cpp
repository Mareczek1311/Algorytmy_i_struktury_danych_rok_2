#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int>& arr, int liczba){

    arr.push_back(liczba);
    int i = arr.size() - 1;


    while (i > 0 && arr[i] > arr[i / 2]) {
        int tmp = arr[i];
        arr[i] = arr[i / 2];
        arr[i / 2] = tmp;
        i = i / 2;
    }

}

int getMax(vector<int>& arr){

    int max = arr[0];

    if(arr.size() == 1){
        arr.pop_back();
        return max;
    }

    swap(arr[0], arr[arr.size()-1]);

    arr.pop_back();

    int i = 0;
    while (2 * i < arr.size()) {
        if (2 * i + 1 < arr.size() && arr[2 * i + 1] > arr[2 * i] && arr[i] < arr[2 * i + 1]) {
            int tmp = arr[i];
            arr[i] = arr[2 * i + 1];
            arr[2 * i + 1] = tmp;
            i = 2 * i + 1;
        }
        else if (arr[i] < arr[2 * i]) {
            int tmp = arr[i];
            arr[i] = arr[2 * i];
            arr[2 * i] = tmp;
            i = 2 * i;
        }
        else {
            break;
        }
    }
    return max;
}

int main() {

    vector<int> heap;

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
                if(heap.empty()){
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
