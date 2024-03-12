#include<iostream>
using namespace std;

int n, m;
int dosi[201][201]; 
int parent[201]; 
int plan[1001];

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

	//freopen_s(new FILE*, "a.txt", "r", stdin);
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dosi[i][j]; 
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> plan[i];
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i; 
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dosi[i][j] == 1) setunion(i, j); 
		}
	}

	

	int target = find(plan[1]); 

	int flag = 0; 
	for (int i = 2; i <= m; i++) {
		if (find(plan[i]) != target) {
			flag = 1; 
			break; 
		}
	}
	if (flag)  cout << "NO";
	else cout << "YES";

	return 0; 
}