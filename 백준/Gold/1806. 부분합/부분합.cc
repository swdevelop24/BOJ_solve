#include<iostream>
#include<algorithm>
using namespace std;

int n; 
int s; 
int minlen; 
int arr[100001]; 

int main() {

	//freopen_s(new FILE*, "a.txt", "r", stdin);
	cin >> n >> s; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	int a = 0; 
	int b = 0;
	int sum = arr[0];
	int minlen = 21e7; 
	int len = 0; 
	for (int a = 0; a < n; a++) {
		while (sum < s && b < n) {
			b++;
			sum += arr[b];
		}
		if (sum >= s) {
			minlen = min(b-a+1, minlen);
		}
	
		sum -= arr[a];
			
	}

	if (minlen == 21e7) {
		cout << 0;
	}
	else
		cout << minlen; 

	return 0; 
}