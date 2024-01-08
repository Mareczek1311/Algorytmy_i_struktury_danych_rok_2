#include <iostream>
#include <vector>
#include <limits.h> 

using namespace std;

void printOptimalParens(const vector<vector<int> > &s, int i, int j, bool isOutermost = true) {
    if (i == j) {
        cout << "A" << i;
    } else {
        if (!isOutermost) {
            cout << "(";
        }
        printOptimalParens(s, i, s[i][j], false);
        printOptimalParens(s, s[i][j] + 1, j, false);
        if (!isOutermost) {
            cout << ")";
        }
    }
}

int main() {
    int n, liczba;

    cin >> n;

    vector<int> p(n + 1);

    for(int i = 0; i <= n; i++){
        cin >> p[i];
    }

    vector<vector<int> > m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int> > s(n + 1, vector<int>(n + 1, 0));

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = -1;
            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j] || m[i][j] == -1) {
                    m[i][j] = cost;
                    s[i][j] = k; // Zapisanie miejsca podziału
                }
            }
        }
    }

    cout << m[1][n] << endl;

    printOptimalParens(s, 1, n);
    cout << endl;

    return 0;
}

