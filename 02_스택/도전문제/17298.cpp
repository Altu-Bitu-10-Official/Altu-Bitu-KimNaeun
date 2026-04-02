#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x;
	cin >> n;
	stack<int> v;
	stack<int> s;
	stack<int> a;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push(x);
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() and s.top() <= v.top()) {
			s.pop();
		}
		if (s.empty()) {
			a.push(-1);
		}
		else {
			a.push(s.top());
		}
		s.push(v.top());
		v.pop();

	}

	for (int i = 0; i < n; i++) {
		cout << a.top() << " ";
		a.pop();
	}

	return 0;
}