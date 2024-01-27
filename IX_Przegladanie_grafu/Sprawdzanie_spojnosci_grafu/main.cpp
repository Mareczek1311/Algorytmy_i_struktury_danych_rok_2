#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int find(vector<int> arr, int value){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == value){
            return 1;
        }
    }
    return -1;
}

string spojnosc(vector<vector<int> > gl, int n){
    for(int k=0; k<n; k++) {
        stack<int> st;
        vector<int> S;
        st.push(k);
        while (!st.empty()) {
            int nb = st.top();
            S.push_back(nb);
            st.pop();
            for (int j = 0; j < gl[nb].size(); j++) {
                if (find(S, gl[nb][j]) == -1) {
                    st.push(gl[nb][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (find(S, i) == -1) {
                return "graf niespojny";
            }
        }
    }

    return "graf spojny";
}

int main() {

    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<vector<int> > gl;
    int liczba;
    int liczba2;
    vector<int> a;

    for(int i=0; i<n; i++){
        gl.push_back(a);
    }

    for(int i=0; i<m; i++){
        cin >> liczba2;
        cin >> liczba;
        gl[liczba2].push_back(liczba);
        gl[liczba].push_back(liczba2);
    }

    cout << spojnosc(gl, n);

    return 0;
}
