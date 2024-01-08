#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int kwota;
    int n;
    cin >> kwota;
    cin >> n;
    int nominaly[n];
    //utworzenie
    vector<int> res;
    int l=0;
    int last = n-1;
    for(int i=0; i<n; i++){
        cin >> nominaly[i];
    }

    sort(nominaly, nominaly+n);

    while(kwota>0 && kwota>=nominaly[0]){
        while(kwota>=nominaly[last]){
            res.push_back(nominaly[last]);
            kwota-=nominaly[last];
            l++;
        }
        last--;
    }


    if(kwota == 0){
        cout << l << endl;

        for(int i=0; i<l; i++){
            cout << res[i] << " ";
        }
    }
    else{
        cout << "NIE";
    }

    return 0;
}
