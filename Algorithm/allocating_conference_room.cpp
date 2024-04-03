// 백준 회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    vector<pair<int, int>> vec;

    int num1, num2;
    for(int i=0;i<N;i++){
        cin>>num1>>num2;
        vec.push_back(make_pair(num2, num1));
    }

    sort(vec.begin(), vec.end());


    int count=0;
    int temp;
    for(int i=0;i<N;i++){
        if(i==0){
            count++;
            temp=i;
        }
        else{
            if(vec[i].second>=vec[temp].first){
                count++;
                temp=i;
            }
            else{
                continue;
            }
        }
    }

    cout<<count;

}