#include<iostream>
using namespace std;

int n, m;
int parent[1000001]; 
int find(int n) {

	if (parent[n] == n) return n; 
	return parent[n] = find(parent[n]); 
}

void setunion(int a, int b) {
	int pa = find(a); 
	int pb = find(b); 
	if (pa == pb) return; 
	parent[pb] = pa; 
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen_s(new FILE*, "a.txt", "r", stdin);
	cin >> n >> m; 

	for (int i = 0; i <= n; i++) {
		parent[i] = i; 
	}

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b; 
		if (cmd == 0) setunion(a, b); 
		if (cmd == 1) {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}

	}

	return 0;
}