#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int count(string num, int n) {
	int sum = 0;
	char ch1 = NULL;
	char* ptr = &ch1;
	for (int i = 0; i < n; i++) {
		if (isdigit(num[i])) {
			ch1 = num[i];
			sum += atoi(ptr);
		}
	}

	return sum;
}

bool comp(const string num_1, const string num_2) {
	int len_1 = num_1.size();
	int len_2 = num_2.size();

	int num1_sum = count(num_1, len_1);
	int num2_sum = count(num_2, len_2);

	if (len_1 != len_2) {
		return len_1 < len_2;
	}
	if (num1_sum != num2_sum) {
		return num1_sum < num2_sum;
	}
	return num_1 < num_2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << nums[i] << '\n';
	}

	return 0;
}