#include<bits/stdc++.h>
using namespace std;

long long l_bound(vector<long long>&v,long long k){
    long long l=0,r=v.size(),mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(v[mid]<k) l=mid+1;
        else r=mid;
    }
    return l; 
}

long long u_bound(vector<long long>&v,long long k){
    long long l=0,r=v.size(),mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(v[mid]<=k) l=mid+1;
        else r=mid;
    }
    return l; 
}

int main()
{
    long long n,i,a,b,sum=0;
    cin >> n;
    vector<long long>v1(n);
    vector<long long>v2(n);
    vector<long long>v3(n);
    for(i=0;i<n;i++) cin >> v1[i];
    for(i=0;i<n;i++) cin >> v2[i];
    for(i=0;i<n;i++) cin >> v3[i];
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    for(i=0;i<n;i++){
        a=l_bound(v1,v2[i]);
        b=n-u_bound(v3,v2[i]);
              
        sum+=(a*b);
    }
    cout << sum << endl;
    return 0;
}
