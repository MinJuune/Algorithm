#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& vecA, vector<int>& vecB, vector<int>& result, int n, int m){
    int count=0;
    int i=0;
    int j=0;
    
    while(i<n && j<m){
        if(i==n-1 && j==m-1){
            if(vecA[i]<vecB[j]){
                result.push_back(vecA[i]);
                result.push_back(vecB[j]);
                count++;
            }
            else{
                result.push_back(vecB[j]);
                result.push_back(vecA[i]);
                count++;
            }
            break;
        }
        else{
            if(vecA[i]<vecB[j]){
                result.push_back(vecA[i]);
                i++;
                count++;
            }
            else{
                result.push_back(vecB[j]);
                j++;
                count++;
            }
        }
    }

    for(int k=0;k<result.size();k++){
        cout<<result[k]<<" ";
    }cout<<endl;
    return count; 
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> vecA;
    vector<int> vecB;
    vector<int> result;

    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        vecA.push_back(num);
    }
    for(int i=0;i<m;i++){
        cin>>num;
        vecB.push_back(num);
    }
    // 일단 배열 세팅
   
    cout<<merge(vecA, vecB, result, n, m);

}