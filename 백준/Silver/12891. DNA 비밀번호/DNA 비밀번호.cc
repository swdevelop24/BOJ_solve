#include<iostream>
using namespace std;

int s; 
int p; 
int cnt[4];//ACGT
string str; 
int mincnt[4];
 

int convert_to_int(char ch) {
	if (ch == 'A') return 0;
	else if (ch == 'C') return 1;
	else if (ch == 'G') return 2;
	else if (ch == 'T') return 3; 
	return -1; 
}

int isvalid(int cnt[], int mincnt[]) {
	for (int i = 0; i < 4; i++) {
		if (cnt[i] < mincnt[i])
			return 0;
	}
	return 1; 
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen_s(new FILE*, "a.txt", "r", stdin);

	cin >> s >> p;
	cin >> str; 

	for (int i = 0; i < 4; i++) {
		cin >> mincnt[i]; 
	}

	for (int i = 0; i < p; i++) {
		cnt[convert_to_int(str[i])]++; 
	}
	int ans = isvalid(cnt, mincnt); 


	for (int i = 1; i < s - p + 1; i++) {
		cnt[convert_to_int(str[i - 1])]--;
		cnt[convert_to_int(str[i+p-1])]++;
		if (isvalid(cnt, mincnt))
			ans++; 
	}

	cout << ans;

	return 0;
}