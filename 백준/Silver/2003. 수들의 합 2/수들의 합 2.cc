#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
int n;
ll m;
int cnt; 
int arr[10001]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen_s(new FILE*, "a.txt", "r", stdin);

	cin >> n >> m; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	ll subsum = 0; 
	int right = 0; 
	for (int left = 0; left < n; left++) {
		while (right < n && subsum < m) {
			subsum += arr[right]; 
			right++; 
		}
		if (subsum == m) {
			cnt++; 
		}
		subsum -= arr[left]; 
	}
	
	cout << cnt; 

	return 0;
}

