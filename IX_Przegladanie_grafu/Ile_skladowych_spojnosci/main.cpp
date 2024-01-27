#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int find(vector<int> arr, int val){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == val){
            return 1;
        }
    }
    return -1;
}

int dfs(vector<vector<int> > arr, int n){
    vector<int> visited;
    int res = 0;
    for(int i=0; i<n; i++){
        if(find(visited, i) == 1){
            continue;
        }

        stack<int> s;
        vector<int>vs;

        s.push(i);

        while(!s.empty()){
            int num = s.top();
            vs.push_back(num);
            s.pop();
            for(int j=0; j<arr[num].size(); j++){
                if(find(vs, arr[num][j]) == -1){
                    s.push(arr[num][j]);
                    if(find(visited, arr[num][j]) == -1){
                        visited.push_back(arr[num][j]);
                    }
                }
            }
        }
        res++;

    }

    return res;
}

int main() {

    int m;
    int n;

    cin >> n >> m;

    vector<vector<int> > arr;
    vector<int> r;
    for(int i=0;i<n; i++){
        arr.push_back(r);
    }

    int l1, l2;
    for(int i=0; i<m; i++){
        cin >> l1 >> l2;
        arr[l1].push_back(l2);
        arr[l2].push_back(l1);
    }

    cout << "Liczba skladowych: " << dfs(arr, n);

    return 0;
}
