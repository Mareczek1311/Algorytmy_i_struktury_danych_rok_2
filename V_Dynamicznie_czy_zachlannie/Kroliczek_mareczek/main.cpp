#include <iostream>

using namespace std;

int main() {

    long n;

    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    long arr[n];

    for(long i=0; i<n; i++){
        cin >> arr[i];
    }

    long dp[n+1];
    dp[0] = 0;
    dp[1] = arr[0];

    for(long i=2; i<n+1; i++){
        dp[i] = max(dp[i-1], dp[i-2] + arr[i-1]);
    }


    cout << dp[n];

    return 0;
}
