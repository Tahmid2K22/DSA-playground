#include<iostream>
using namespace std;

int bin_search(int *a,int n,int k){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]==k) return 1;
        else if(a[mid]<k) l=mid+1;
        else r=mid-1;
    }
    return 0;
}

int main()
{
    int n,k;// n for size and k for query number
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    while(k--){
        int num;//Number to search
        cin >> num;
        if(bin_search(a,n,num)) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
    
    return 0;
}
