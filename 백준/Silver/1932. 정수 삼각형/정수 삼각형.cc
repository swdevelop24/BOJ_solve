#include<iostream>
#include<algorithm>
using namespace std;

int n;
int tri[510][510]; 
int dp[510][510]; 
int main() {

	cin >> n; 
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= y; x++) {
			cin >> tri[y][x]; 
		}
	}

	dp[1][1] = tri[1][1]; 
	for (int y = 2; y <= n; y++) {
		for (int x = 1; x <= y; x++) {
			dp[y][x] =max(dp[y-1][x], dp[y-1][x-1]) + tri[y][x];
		}
	}

	int ans = 0; 
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[n][i]); 
	}

	cout << ans; 

	
	

	return 0;
}