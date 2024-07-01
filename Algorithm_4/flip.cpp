// 백준 뒤집기

#include <iostream>
using namespace std;
#include <string>

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    cin>>s;

    int zero=0;
    int one=0;
    char temp=s[0];
    if(temp=='0'){
        zero++;
    }
    else if(temp=='1'){
        one++;
    }

    for(int i=1;i<s.size();i++){
        if(s[i]==temp){
            continue;
        }
        else{
            if(s[i]=='0'){
                zero++;
                temp='0';
            }
            else if(s[i]=='1'){
                one++;
                temp='1';
            }
        }
    }

    if(one>zero){
        cout<<zero;
    }
    else{
        cout<<one;
    }
}