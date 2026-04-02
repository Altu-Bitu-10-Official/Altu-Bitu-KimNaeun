#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int len;
	char c;

	while (true) {
		string str;
		getline(cin, str);
		stack<char> str_list;

		if (str == ".") {
			break;
		}

		len = str.size();
		for (int i = 0; i < len; i++) {
			if (str[i] == '(' or str[i] == '[') {
				str_list.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!str_list.empty() and str_list.top() == '(') {
					str_list.pop();
				}
				else {
					str_list.push(str[i]);
				}
			}
			else if (str[i] == ']') {
				if (!str_list.empty() and str_list.top() == '[') {
					str_list.pop();
				}
				else {
					str_list.push(str[i]);
				}
			}
		}

		if (str_list.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

	}

	return 0;
}