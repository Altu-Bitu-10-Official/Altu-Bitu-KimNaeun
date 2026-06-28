#include <iostream>

using namespace std;

int n;
int min_num = 1000000000;
int max_num = -1000000000;
int nums[11];
int calc[4];
int check[4] = {0, 0, 0, 0};

void backtrack(int b, int cnt) {
    if (cnt == n - 1) {
        min_num = min(min_num, b);
        max_num = max(max_num, b);
        return;
    }

    int x = b;
    int y = nums[cnt + 1];

    for (int i = 0; i < 4; i++) {
        if (calc[i] == check[i]) {
            continue;
        }

        if (i == 0) {
            check[i]++;
            backtrack(x + y, cnt + 1);
        }else if (i == 1) {
            check[i]++;
            backtrack(x - y, cnt + 1);
        }else if (i == 2) {
            check[i]++;
            backtrack(x*y, cnt + 1);
        }else if (i == 3) {
            check[i]++;
            backtrack(x/y, cnt + 1);
        }

        check[i]--;
    }
}

int main() {
    cin >> n;
    for (int i= 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> calc[i];
    }

    backtrack(nums[0], 0);

    cout << max_num << "\n";
    cout << min_num << "\n";

    return 0;
}
