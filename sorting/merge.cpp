#include <iostream>
using namespace std;

const int MX = 1000;

int N;
int merged[MX];
int arr1[MX];
int arr2[MX];

void merge(){
    int index1 = 0;
    int index2 = 0;
    int indexMerged = 0;

    while(index1 < N && index2 < N){
        if(arr1[index1] < arr2[index2]){
            merged[indexMerged] = arr1[index1];

            index1++;
            indexMerged++;
        } else {
            merged[indexMerged] = arr2[index2];
            
            index2++;
            indexMerged++;    
        }
    }

    while(index1 < N) {
        merged[indexMerged] = arr1[index1];
        index1++;
        indexMerged++;
    }

    while(index2 < N) {
        merged[indexMerged] = arr2[index2];
        index2++;
        indexMerged++;
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<N;i++){
        cin>>arr2[i];
    }

    merge();

    for(int i=0;i<2*N;i++){
        cout<<merged[i]<<' ';
    }
    cout<<endl;
    return 0;
}