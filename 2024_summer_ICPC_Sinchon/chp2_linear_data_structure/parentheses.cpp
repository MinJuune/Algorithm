// 백준 괄호

#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	string str;
	int size = 0;

	stack<char> s;
	int count = 0;

	for (int i = 0; i < T; i++) {
		cin >> str;
		size = str.size();
		
		 
		for (int j = 0; j < size; j++) {
			if (str[j] == '(') {
				s.push('(');
			}
			else if (str[j] == ')') {
				if (s.empty()) {
					count++;
					break;
				}
				else {
					s.pop();
				}
			}
		}

		if (count == 0 && s.empty()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

		count = 0;
		while (!s.empty()) {
			s.pop();
		}

		


	}
}