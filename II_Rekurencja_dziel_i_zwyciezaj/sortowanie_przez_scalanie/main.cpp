#include <iostream>

using namespace std;

void merge(int *tab, int start, int mid, int end){
    int leftCap = mid+1 - start;
    int rightCap = (end)-(mid) ;

    int left[leftCap];
    int right[rightCap];

    int curr_inx = 0;
    for(int i=start; i<mid+1; i++){
        left[curr_inx] = tab[i];
        curr_inx++;
    }

    curr_inx=0;
    for(int i=mid+1; i<end+1; i++){
        right[curr_inx] = tab[i];
        curr_inx++;

    }

    int l=0, r=0;
    curr_inx = start;
    while(l<leftCap && r<rightCap){
        if(left[l] < right[r]){
            tab[curr_inx] = left[l];
            l++;
        }
        else{
            tab[curr_inx] = right[r];
            r++;
        }
        curr_inx++;
    }

    while(l<leftCap){
        tab[curr_inx] = left[l];
        l++;
        curr_inx++;
    }

    while(r<rightCap){
        tab[curr_inx] = right[r];
        r++;
        curr_inx++;
    }

}

void mergeSort(int *tab, int start, int end){
    if(end-start+1 <= 1){
        return;
    }

    int mid = (end+start)/2;

    mergeSort(tab, start, mid);
    mergeSort(tab, mid+1, end);

    merge(tab, start, mid, end);
}

int main() {

    int n;
    cin >> n;
    int* tab = new int[n];

    for(int i=0;i<n; i++){
        cin >> tab[i];
    }


    mergeSort(tab, 0, n-1);

    for(int i=0; i<n-1;i++){
        cout << tab[i] << ", ";
    }
    cout << tab[n-1];

    delete[] tab;


    return 0;
}
