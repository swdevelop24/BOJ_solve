#include<iostream>
#include<algorithm>
using namespace std;

int t, n, m;
int arr[20000];
int brr[20000];
int ret;

//arr에 있는 target 보다 작은 brr값이 몇개 있는지 찾아야함. 
int bs(int blen, int tar) {
	int cnt = 0;
	int maxi = 0;
	int mid = 0;
	int s = 0;
	int e = blen-1;
	while (s <= e) {
		mid = (s + e) / 2;
		if (brr[mid] < tar) {
			cnt = mid +1;
			s = mid + 1;
		}
		else {
			e = mid - 1;

		}
	}
	return cnt;
}

int main() {

	//freopen_s(new FILE*, "b.txt", "r", stdin);
	cin >> t;

	for (int i = 0; i < t; i++) {

		int alen, blen;
		cin >> alen >> blen;
		ret = 0;

		for (int x = 0; x < alen; x++) {
			cin >> arr[x];
		}

		for (int x = 0; x < blen; x++) {
			cin >> brr[x];
		}

		sort(arr, arr + alen);
		sort(brr, brr + blen);

		int cnt = 0;
		for (int i = 0; i < alen; i++) {
			cnt += bs(blen, arr[i]);
		}

		cout << cnt << endl;

	}
	return 0;
}