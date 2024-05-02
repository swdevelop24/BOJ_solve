#include<iostream>
using namespace std;
int n, m; 
int path[10];
int used[10];

void dfs(int lev) {
	if (lev == m) {
		for (int i = 0; i < m; i++) {
			cout << path[i] << " "; 
		}
		cout << "\n"; 
		return; 
	}
	for (int i = 1; i <= n; i++) {
		
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = i;
		dfs(lev + 1); 
		path[lev] = 0;
		used[i] = 0; 
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; 
	dfs(0); 

	return 0; 
}