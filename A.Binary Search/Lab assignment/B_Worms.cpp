#include<bits/stdc++.h>
using namespace std;

#define ll long long


ll l_bound(vector<ll>&v,ll k){
    ll l=0,r=v.size()-1,mid;

    while(l<r){
        mid=l+(r-l)/2;
        if(v[mid]<k) l=mid+1;
        else r=mid;
    }
    return l;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    for(ll i=1;i<n;i++) v[i]+=v[i-1];
    ll q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        cout<< l_bound(v,x)+1 <<'\n';
    }
}