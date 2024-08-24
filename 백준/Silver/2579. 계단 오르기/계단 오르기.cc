#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[310]; 
int dp[310][2]; 

int main() {

	//freopen_s(new FILE*, "a.txt", "r", stdin);
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> arr[i]; 
	}


	dp[1][0] = 0;
	dp[1][1] = arr[1];
	if (n >= 2) {
		dp[2][0] = arr[2];
		dp[2][1] = arr[2] + arr[1];

	}
	
	for (int i = 3; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][0]+arr[i], dp[i - 2][1] + arr[i]) ;
		dp[i][1] = dp[i - 1][0] + arr[i]; 
	}
	
	cout << max(dp[n][0], dp[n][1]); 

	return 0;
}


