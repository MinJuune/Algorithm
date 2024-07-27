// 백준 스택

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;

	int N = 0;
	string str;
	int num = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push") {
			cin >> num;
			s.push(num);
		}
		else if (str == "pop") {
			if (!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else {
				cout << "-1\n";
			}
		}
		else if (str == "size") {
			cout << s.size() << "\n";
		}
		else if (str == "empty") {
			if (!s.empty()) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if (str == "top") {
			if (!s.empty()) {
				cout << s.top() << "\n";
			}
			else {
				cout << "-1\n";
			}
		}
	}


}