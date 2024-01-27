#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    } 
    
    int i = 1;
    int size = 0;
    int maxLvl = 0;
    
    while(size<n){
        size += i;
        maxLvl += 1;
        i++;
    }
    
    vector<vector<int> > dp;
    int idx = 0;
    for(int i=1; i<=maxLvl; i++){
        
        vector<int> a;
        dp.push_back(a);
        for(int j=0; j<i; j++){
            dp[i-1].push_back(arr[idx]);
            idx ++;
        }
    }

    maxLvl-=2;

    while(maxLvl >= 0){
        for(int i=0; i<dp[maxLvl].size(); i++){
            dp[maxLvl][i] += max(dp[maxLvl+1][i], dp[maxLvl+1][i+1]);
        }
        maxLvl--;
    }

    for(int i=0; i<dp.size();i++){
        for(int j=0; j<dp[i].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        
    cout << dp[0][0]<<endl;

    return 0;
}
