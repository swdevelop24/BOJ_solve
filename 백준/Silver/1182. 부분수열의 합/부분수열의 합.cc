#include<iostream>
using namespace std;
int n;
int arr[30]; 
int s; 
int cnt; 

void dfs(int lev, int sum) {
	if (lev == n+1) {
		if(sum == s)
			cnt++; 
		return; 
	}


	dfs(lev + 1, sum + arr[lev]);
	dfs(lev + 1, sum); 

}

int main() {

	//freopen_s(new FILE*, "a.txt", "r", stdin); 
	cin >> n >> s; 
	for (int i = 1; i <= n; i++) {
		cin >> arr[i]; 
	}

	dfs(1,0);
	if(s==0){
        cnt--;
    }
    cout << cnt;
    return 0; 
}