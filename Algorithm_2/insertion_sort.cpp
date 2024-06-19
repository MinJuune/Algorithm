#include <iostream> 
using namespace std;

// 11 33 23 45 13 25 8 135
// 83 72 65 54 47 33 29 11

void insertion_sort(int arr[]){

    for(int i=1;i<8;i++){  // 인덱스 0번은 이미 정렬된것으로 판단
        int key=arr[i];        // 살펴볼 값 key
        // 현재 i-1번까지 정렬된 상태
        // 비교는 i-1번째부터 1번까지 역순으로 비교한다.
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
        
        //중간과정 출력
        for(int i=0;i<8;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
}

int main(){
    int arr1[8]={11,33,23,45,13,25,8,135};
    int arr2[8]={83,72,65,54,47,33,29,11};


    for(int i=0;i<8;i++){
        cout<<arr1[i]<<" ";
    }cout<<endl;

/*
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }cout<<endl;
    cout<<endl;*/

    insertion_sort(arr1);
//    insertion_sort(arr2,n);

    for(int i=0;i<8;i++){
        cout<<arr1[i]<<" ";
    }cout<<endl;

/*
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }*/
}
