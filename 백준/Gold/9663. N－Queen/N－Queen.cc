#include<iostream>
using namespace std;

int n; 
int col[20]; 
int cnt; 


bool attack(int r1,int c1, int r2, int c2) {
	if (c1 == c2) return true; 
	if ((r1 - c1) == (r2 - c2)) return true;
	if ((r1 + c1) == (r2 + c2)) return true;
	return false; 
}
void dfs(int row) {
	if (row == n + 1) {
		cnt++; 
		return; 
	}

	for (int c = 1; c <= n; c++) {
		bool possible = true; 
		for (int x = 1; x <= row - 1; x++) {
			if (attack(row, c, x, col[x])) {
				possible = false; 
				break; 
			}
		}

		if (possible) {
			col[row] = c; 
			dfs(row + 1); 
			col[row] = 0;
		}
	}
}

int main() {
	cin >> n;
	dfs(1); 

	cout << cnt;
	return 0; 
}