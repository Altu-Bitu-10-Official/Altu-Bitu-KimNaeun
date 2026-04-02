#include <iostream>
#include <stack>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	int len = str.size();
	stack<char> c;
	map<char, int> calc;
	calc['+'] = 1; calc['-'] = 1;
	calc['*'] = 2; calc['/'] = 2;
	calc['('] = 0;

	for (int i = 0; i < len; i++) {
		if (isalpha(str[i])) {
			cout << str[i];
		}
		else if (str[i] == '(') {
			c.push(str[i]);
		}
		else if (str[i] == ')') {
			while (c.top() != '(') {
				cout << c.top();
				c.pop();
			}
			c.pop();
		}
		else {
			while (!c.empty() and calc[str[i]] <= calc[c.top()]) {
				if (calc[c.top()] != 0) {
					cout << c.top();
				}
				c.pop();
			}	
			c.push(str[i]);
		}
	}

	while (!c.empty()) {
		if (calc[c.top()] != 0) {
			cout << c.top();
		}
		c.pop();
	}

	return 0;
}