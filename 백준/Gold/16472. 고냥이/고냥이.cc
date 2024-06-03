#include<iostream>
using namespace std;

int n;
string str;

int dat[27];
int cnt; 


void add(char ch) {
	dat[ch - 'a']++;
	if (dat[ch - 'a'] == 1) cnt++;

}

void sub(char ch) {
	dat[ch - 'a']--;
	if (dat[ch - 'a'] == 0) cnt--;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen_s(new FILE*, "a.txt", "r", stdin);

	cin >> n;
	cin >> str;

	int len = str.length();
	int maxlen = 0; 

	for (int left = 0, right = 0; right < len; right++) {
		add(str[right]);
		while(cnt > n) {
			sub(str[left]);
			left++; 
		}
		maxlen = max(maxlen, right - left + 1);
	}

	cout << maxlen;


	return 0;
}