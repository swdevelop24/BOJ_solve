#include<iostream>
using namespace std;

int n; 
int k; 
int dp[110000]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 

	cin >> n >> k; 
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		for (int t = k; t >= w; t--) {
			dp[t] = max(dp[t], dp[t - w] + v); 
		}
	}

	cout << dp[k]; 

	return 0;
}