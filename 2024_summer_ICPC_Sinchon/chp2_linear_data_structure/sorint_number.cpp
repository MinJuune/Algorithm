// 백준 수 정렬하기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int num = 0;
	vector<int> vec;

	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		cout << vec[i] << '\n';
	}
	
	
}