#include<iostream>
using namespace std;

int dp[1100][1100];
int n;


int main() {
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }


    for (int i = 2; i <= n; i++) {
        for (int k = 0; k <= 9; k++) {
            for (int t = 0; t <= k; t++) {
                dp[i][k] += dp[i - 1][t];
                dp[i][k] %= 10007;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i <= 9; i++) {
        ret += dp[n][i];
        ret %= 10007;
    }
    cout << ret;
    return 0;
}