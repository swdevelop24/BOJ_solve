#include<iostream>
#include<algorithm>
using namespace std;

int L;
int C;
char arr[20]; 
char path[20]; 
int ans; 

int isVowel(int idx) {
	if (arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i' 
		|| arr[idx] == 'o' || arr[idx] == 'u')
		return 1; 
	return 0; 
}
void dfs(int lev, int idx, int vcnt) {
	if (lev == L) {
		if (vcnt >= 1 && L - vcnt >= 2) {
			cout << path; 
			cout << "\n"; 
		}
		return; 
	}

	if (idx < C) {

		path[lev] = arr[idx];
		int v = 0;
		if (isVowel(idx)) v=1; 
		dfs(lev + 1, idx + 1, vcnt+v);
		path[lev] = 0;
		dfs(lev, idx + 1, vcnt);
	}
	
}

int main() {

	//freopen_s(new FILE*, "a.txt", "r", stdin); 

	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> arr[i]; 
	}
	sort(arr, arr + C); 
	dfs(0,0,0); 
	return 0; 
}