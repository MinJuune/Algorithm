// 백준 1로 만들기

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
    int N;
    cin >> N;
    

    int temp;
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            dp[i] = 0;
        }
        else if (i == 2) {
            dp[i] = 1;
        }
        else if (i == 3) {
            dp[i] = 1;
        }
        else {
            if (i % 3 == 0 && i % 2 == 0) {
                temp = min(dp[i - 1] + 1, dp[i / 3] + 1);
                dp[i] = min(temp, dp[i / 2] + 1);
            }
            else if (i % 3 == 0 && i % 2 != 0) {
                dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
            }
            else if (i % 3 != 0 && i % 2 == 0) {
                dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
            }
            else {
                dp[i] = dp[i - 1] + 1;
            }
        }
    }
    cout << dp[N];
}