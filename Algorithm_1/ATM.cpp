// 백준 ATM

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;
    vector<int> vec;
    vector<int> accumulate;

    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    for(int i=0;i<N;i++){
        if(i==0){
            accumulate.push_back(vec[i]);
        }
        else{
            accumulate.push_back(accumulate[i-1]+vec[i]);
        }
    }

    int sum=0;
    for(int i=0;i<vec.size();i++){
        sum+=accumulate[i];
    }
    cout<<sum;
}