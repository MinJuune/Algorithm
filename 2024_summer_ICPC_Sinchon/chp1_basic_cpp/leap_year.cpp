// 백준 윤년

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int year;
    cin>>year;
    if((year%4==0 && year%100!=0) || year%400==0){
        cout<<1;
    }
    else{
        cout<<0;
    }
}