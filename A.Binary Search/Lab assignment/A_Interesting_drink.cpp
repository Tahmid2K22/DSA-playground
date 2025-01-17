#include<bits/stdc++.h>
using namespace std;

#define ll long long


ll u_bound(vector<ll>&v,ll k){
    ll l=0,r=v.size(),mid;

    while(l<r){
        mid=l+(r-l)/2;
        if(v[mid]<=k) l=mid+1;
        else r=mid;
    }
    return l;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    ll q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        ll index = u_bound(v,x);
        cout<< index <<'\n';
    }
}