//백준 이항계수2

#include <iostream>
using namespace std;

int B[1001][1001] = { 0, };
// main에 배열 선언하면 stack 메모리가 부족하여 전역 변수로 선언

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                B[i][j] = 1;
            }
            else {
                B[i][j] = (B[i - 1][j] + B[i - 1][j - 1]) % 10007;
            }
        }
    }

    cout << B[N][K];
}
