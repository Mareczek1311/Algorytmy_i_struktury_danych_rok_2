#include <iostream>

using namespace std;

int main() {

    int n;

    cin >> n;

    float arr[n][3];
    for(int i=0; i<n; i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
        arr[i][2] = i+1;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i][1] > arr[j][1]){
                swap(arr[i], arr[j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j][0] * arr[i][1] > arr[i][0] * arr[j][1]){
                swap(arr[j], arr[i]);
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i][2] << endl;
    }

    return 0;
}
