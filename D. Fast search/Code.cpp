//problem: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

#include<iostream>
#include<algorithm>
using namespace std;


//author: Tahmid Hossain Chowdhury Mahin
void bsort(int *a,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1-i;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
    return;        
}
int index1(int *a,int n,int num){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]>=num)r=mid-1;
        else l=mid+1;
    }
    return l;
}

int index2(int *a,int n,int num){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]<=num) l=mid+1;
        else r=mid-1;
    }
    return l;
}

int main()
{
    int n,k;// n for size and k for query number
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    bsort(a,a+n);
    cin >> k;
    while(k--){
        int l,r;//Input Range
        cin >> l>>r;
        int count =index2(a,n,r)-index1(a,n,l);
        if (count > 0) {
            cout << count << endl;
        } else {
            cout << 0 << endl;
        }
    }
    
    return 0;
}
