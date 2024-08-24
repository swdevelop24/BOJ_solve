#include<iostream>
using namespace std;

int d[12];
int n;
int t;

int dp(int& n) {
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }
    return d[n];

}

int main() {

    //freopen_s(new FILE*, "a.txt", "r", stdin);

    cin >> t;


    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp(n) <<"\n";
    }
    return 0;
}