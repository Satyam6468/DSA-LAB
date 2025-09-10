#include <bits/stdc++.h>
using namespace std;
void merg2Array(int l1,int l2,int arr1[],int arr2[],int mergedArr[]){
    int c1=0,c2=0;
    int i;
    for(i=0;i<l1+l2;i++){
        if(c1==l1){
            for(int j=c2;j<l2;j++){
                mergedArr[i]=arr2[c2];
                c2++;
                i++;
            }
            break;
        }
        if(c2>=l2){
            for(int j=c1;j<l1;j++){
                mergedArr[i]=arr1[c1];
                c1++;
                i++;
            }
            break;
        }
        if(arr1[c1]<=arr2[c2]){
            mergedArr[i]=arr1[c1];
            c1++;
        }
        else{
            mergedArr[i]=arr2[c2];
            c2++;
        }
    }
}
void inputShortedArray(int a[],int len){
    int b,temp=len;
    cout<<"Enter element";
    cin>>b;
    for(int i=len-1;i>=0;i--){
        if(a[i]>b){
            a[i+1]=a[i];
            temp--;
        }
        else{
            break;
        }
    }
    a[temp]=b;
}
int main(){
    int mergedArr[100];
    int arr1[]={1,4,7,13,15};
    int arr2[]={2,5,8,9,12,35,77};
    merg2Array(5,7,arr1,arr2,mergedArr);
    for(int i=0;i<12;i++){
        printf("%d  ",mergedArr[i]);
    }
}