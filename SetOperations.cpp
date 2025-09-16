#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> v1){
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
}
vector<int> Union(vector<int> v1,vector<int> v2,vector<int> v3){
    int temp,n1,n2;
    n1=v1.size();
    n2=v2.size();
    for(int i=0;i<n1;i++){
        temp=v1[i];
        int check=0;
        for(int j=0;i<v3.size();j++){
            if(temp==v3[j]){
                check++;
            }
        }
        if(check==0){
            v3.push_back(temp);
        }
    }
    for(int j=0;j<n2;j++){
        temp=v2[j];
        int check=0;
        for(int i=0;i<v3.size();i++){
            if(temp==v3[i]){
                check++;
            }
        }
        if(check==0){
            v3.push_back(temp);
        }
    }
    return v3;
}
vector<int> intersection(vector<int> v1,vector<int> v2,vector<int> v3){
    int temp,n1,n2;
    n1=v1.size();
    n2=v2.size();
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(v1[i]==v2[j]){
                v3.push_back(v1[i]);
            }
        }
    }
    return v3;
}
int main() {
    int n1,n2,temp;
    cout<<"enter length of set 1 and set 2:";
    cin>>n1>>n2;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    cout<<"Enter elements of set 1:";
    for(int i=0;i<n1;i++){
        cin>>temp;
        v1.push_back(temp);
    }
    cout<<"Enter elements of set 2:";
    for(int i=0;i<n2;i++){
        cin>>temp;
        v2.push_back(temp);
    }
    //Intersection
    
    printVector(v3);
}