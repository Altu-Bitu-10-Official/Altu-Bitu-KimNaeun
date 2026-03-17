#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> str_list;

int count_str(const string& str, int len) {
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j < len - i + 1; j++) {
			str_list.insert(str.substr(j, i));
		}
	}
	return str_list.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	int len = str.size();

	cout << count_str(str, len);

	return 0;
}