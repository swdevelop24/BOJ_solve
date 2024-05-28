#include<iostream>
#include<cmath>
using namespace std;

int n, s; 
int arr[100001]; 

int main() {
	//freopen_s(new FILE*, "a.txt", "r", stdin);
	cin >> n >> s; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	int b = -1; 
	int sum = 0;
	int ret = n + 1; 
	for (int a = 0; a < n; a++) {
		while (b + 1 < n && sum < s) {
			b++;
			sum += arr[b]; 
		}
		if (sum >= s) {
			ret = min(ret, b - a + 1); 
		}
		sum -= arr[a]; 
	}

	if (ret == n + 1) cout << 0;
	else cout << ret;


	return 0;
}




