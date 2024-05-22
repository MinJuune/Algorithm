// 백준 잃어버린 괄호

#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string str;
    cin >> str;

    int str_size=str.size();
    
    bool already=false;

    for(int i=0;i<str_size;i++){
        if(str[i]=='-' && already==false){
            already=true;
        }
        else if(str[i]=='+' && already==true){
            str[i]='-';
        }
    }
    // 일단 -뒤에 나오는 +는 전부 -로 바꿈


    queue<int> q;
    int result = 0;
    int first = 0;
    char temp_op;
    int arr[50];
    int cnt = -1;
    int temp = 0;
    for (int i = 0; i <= str.size(); i++) {
        if (str[i]>='0' && str[i]<='9') {
            cnt++;
            if (str[i] == '0') {
                q.push(0);
            }
            else if (str[i] == '1') {
                q.push(1);
            }
            else if (str[i] == '2') {
                q.push(2);
            }
            else if (str[i] == '3') {
                q.push(3);
            }
            else if (str[i] == '4') {
                q.push(4);
            }
            else if (str[i] == '5') {
                q.push(5);
            }
            else if (str[i] == '6') {
                q.push(6);
            }
            else if (str[i] == '7') {
                q.push(7);
            }
            else if (str[i] == '8') {
                q.push(8);
            }
            else if (str[i] == '9') {
                q.push(9);
            }
        }
        else {
            while (!q.empty()) {
                temp += (q.front() * pow(10, cnt));
                cnt--;
                q.pop();
            }
            if (first == 0) {
                first = 1;
                result = temp;
            }
            else {
                if (temp_op == '+') {
                    result += temp;
                }
                else {
                    result -= temp;
                }
            }
            if (str[i] == '+') {
                temp_op = '+';
            }
            else {
                temp_op = '-';
            }
            temp = 0;
        }
    }
    cout << result;
}