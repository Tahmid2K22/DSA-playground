//Problem:https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
#include<iostream>
using namespace std;

//Author: Tahmid Hossain Chowdhury Mahin 
int index(int *a,int n,int num){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]>=num)r=mid-1;
        else l=mid+1;
    }
    return r+2;
}

int main()
{
    int n,k;// n for size and k for query number
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    while(k--){
        int num;//Input number
        cin >> num;
        cout<<index(a,n,num)<<endl;
    }
    
    return 0;
}
