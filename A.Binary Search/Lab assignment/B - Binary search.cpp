#include <iostream>
#include <vector>
using namespace std;
int ok;


int l_bound(vector<int> &v, int k) {
    int l=0,r=v.size()-1, mid;
    while(l<=r) {
        mid=(l+r)/2;
        if(v[mid]==k) ok=1;
        if (v[mid]>=k) {
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,q,k;
    cin>>n>>q;
    vector<int> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
    }
    while (q--){
        cin>>k;
        ok=0;
        int ans= l_bound(v, k);
        if (ans <n && ok) {
            cout << ans << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
