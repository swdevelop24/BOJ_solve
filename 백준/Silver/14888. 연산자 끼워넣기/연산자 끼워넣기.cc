#include<iostream>
#include<algorithm>
using namespace std; 

int n;
int arr[15]; 
int op[4]; 
int maxi = -21e8; 
int mini = 21e8; 

int calculate(int op1, int op2, int op) {
	int ret = 0; 
	if (op == 0) {
		return op1 + op2; 
	}
	else if (op == 1) {
		return op1 - op2; 
	}
	else if (op == 2) {
		return op1 * op2;
	}
	else if (op == 3) {
		return op1 / op2;
	}
	
}

void dfs(int lev, int val) {
	if (lev == n - 1) {
		maxi = max(maxi, val); 
		mini = min(mini, val); 
		return; 
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] >= 1) {
			int nextval = calculate(val, arr[lev + 1], i);
			op[i]--; 
			dfs(lev + 1, nextval); 
			op[i]++; 
		}
	}
}

int main() {
	
	//freopen_s(new FILE*, "a.txt", "r", stdin); 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i]; 
	}

	dfs(0, arr[0]); 
	cout << maxi << "\n" << mini; 
	
	return 0; 
}