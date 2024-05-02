#include<iostream>
using namespace std;
int n, m; 
int path[8]; 
void dfs(int lev) {
	if (lev == m) {
		for (int i = 1; i <= lev; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return; 
	}
	for (int i = 1; i <= n; i++) {
		path[lev+1] = i;
		dfs(lev + 1); 
		path[lev+1] = 0;
	}
}

int main() {
	cin >> n >> m; 
	dfs(0); 
}