// 백준 단어공부

#include <iostream>
using namespace std;

int arr[27]={0,};

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    cin>>s;
    int size=s.size();
    for(int i=0;i<size;i++){
        if(s[i]>=65 && s[i]<=90){
            arr[s[i]-65]++;
        }
        else if(s[i]>=97 && s[i]<=122){
            arr[s[i]-97]++;
        }
    }

    int max=0;
    int temp=0;
    for(int i=0;i<26;i++){
        if(max<arr[i]){
            max=arr[i];
            temp=i;
        }
    }

    int isOne=0;
    for(int i=0;i<26;i++){
        if(max==arr[i]){
            isOne++;
        }
    }
    if(isOne==1){
        cout<<(char)(temp+65);
    }
    else{
        cout<<"?";
    }
}