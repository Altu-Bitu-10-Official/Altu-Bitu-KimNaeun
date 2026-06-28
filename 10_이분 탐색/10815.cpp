#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int n, int card, vector<int> &nums1) {
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (nums1[mid] == card) {
            return 1;
        }
        else if (nums1[mid] > card) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}


int main() {
    int n, m, card, ans;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    sort(nums1.begin(), nums1.end());

    cin >> m;
    while (m--) {
        cin >> card;
        ans = binarySearch(n, card, nums1);
        cout << ans << " ";
    }

    cout << "\n";

    return 0;
}