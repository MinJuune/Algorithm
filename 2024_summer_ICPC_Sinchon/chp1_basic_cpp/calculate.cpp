// 백준 사칙연산

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A,B;
    cin>>A>>B;

    cout<<A+B<<'\n';
    cout<<A-B<<'\n';
    cout<<A*B<<'\n';
    cout<<A/B<<'\n';
    cout<<A%B;
}