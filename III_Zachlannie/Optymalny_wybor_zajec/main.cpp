#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    if(n == 0){
        cout << 0;
        return 0;
    }

    int arr[n][2];


    for(int i=1; i<n; i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    //sort
    int tmp[2];
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i][1] > arr[j][1]) {
                tmp[0] = arr[i][0];
                tmp[1] = arr[i][1];

                arr[i][0] = arr[j][0];
                arr[i][1] = arr[j][1];

                arr[j][0] = tmp[0];
                arr[j][1] = tmp[1];
            }
        }
    }


    //wybrac najoptymajniej w danym momencie
    int res = 0;
    int koniecOstatniegoZajecia = -1;
    for(int i=0; i<n; i++){

        if(arr[i][0] >= koniecOstatniegoZajecia){
            koniecOstatniegoZajecia = arr[i][1];
            res++;
        }
    }
    cout << res;

    return 0;
}