// 피보나치_dp

#include <iostream>
using namespace std;

int dp[26];

int fibo(int n) {
    for (int i = 0; i < n + 1; i++) {
        if (i <= 1) {
            dp[i] = i;
        }
        else {
            dp[i] = (dp[i - 1] + dp[i - 2]);
        }
    }

    return dp[n];
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    cout << fibo(n);
}