#include <iostream>

using namespace std;

void sort(int* tab, int n){
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            if(tab[j] < tab[i]){
                swap(tab[j],tab[i]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *tab = new int[n];

    for(int i=0; i<n; i++){
        cin >> tab[i];
    }

    sort(tab, n);

    for(int i=0; i<n; i++){
        cout<<tab[i] << " ";
    }

    return 0;
}