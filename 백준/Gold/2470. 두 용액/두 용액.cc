#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int arr[100001]; 
int main() {

	//freopen_s(new FILE*, "a.txt", "r", stdin); 

	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n);

	int minsum = 21e8; 
	int sum = 0; 
	int a = 0; 
	int b = n - 1; 
	int ret1 = 0, ret2 = 0; 
	while (a < b) {
		sum = arr[a] + arr[b];
		if (minsum > abs(sum)) {
			minsum = abs(sum);
			ret1 = arr[a]; 
			ret2 = arr[b]; 
 		}
		if (sum < 0) {
			a++;
		}
		else b--;
	}
	
	cout << ret1 << " " << ret2;

	return 0; 
}