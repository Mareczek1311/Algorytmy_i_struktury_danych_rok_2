#include <iostream>
#include <vector>
using namespace std;

int main() {

    int value, n;
    cin >> value >> n;

    vector<int> A;
    int liczba;
    for (int i = 0; i < n; i++) {
        cin >> liczba;
        A.push_back(liczba);
    }


    vector<int> T (value+1, value+1);
    vector<int> S(value+1, -1);

    T[0] = 0;
    S[0] = 0;

    for(int i=1; i<=value; i++){
        for(int k=0; k<n;k++){
            if (i >= A[k] && T[i - A[k]] + 1 < T[i]) {
                T[i] = 1 + T[i-A[k]];
                S[i] = A[k];
            }
        }
    }

    if(T[value] == value+1){
        cout << "NIE";
    }
    else {
        cout << T[value] << endl;
        while (value > 0) {
            cout << S[value] << " ";
            value = value - S[value];
        }

    }
    return 0;
}