#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<int> cnt(100001, 0);

    int ans = 0;
    int left = 0;

    for (int right = 0; right < numbers.size(); right++) {
        cnt[numbers[right]]++;
        while (cnt[numbers[right]] > k) {
            cnt[numbers[left]]--;
            left++;
        }
        if (ans < right - left + 1) {
            ans = right - left + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}