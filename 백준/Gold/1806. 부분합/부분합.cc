#include<iostream>
#define ll long long 
using namespace std;

int n; 
int s; 
int minlen = 21e8;
int arr[100001]; 
ll subsum; 


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen_s(new FILE*, "a.txt", "r", stdin);

	cin >> n; 
	cin >> s; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}


	int right = -1; 
	for (int left = 0; left < n; left++) {
		while (subsum < s && right < n) {
			right++; 
			subsum += arr[right]; 
		}
		if (subsum >= s) {
			minlen = min(minlen, right - left + 1);
		}
		subsum -= arr[left];

	}

	if (minlen == 21e8) cout << 0;
	else cout << minlen; 
	return 0;
}
