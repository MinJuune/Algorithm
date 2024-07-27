// 백준 큐

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;
	int N = 0;
	string str;
	int num = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			if (!q.empty()) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if (str == "front") {
			if (!q.empty()) {
				cout << q.front() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
		else if (str == "back") {
			if (!q.empty()) {
				cout << q.back() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}
}