#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int tc;scanf("%d",&tc);
    while(tc--){
        int n;scanf("%d",&n);
        vector<int> v(n);
        for(int i=0;i<n;i++)scanf("%d",&v[i]);
        unordered_map<int,ll> m;
        m[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--)
            m[i]=m[i+1]+v[i];
        ll ans = 0;
        for(int i=0;i<n;i++)
            ans+=m[i]*v[i];
        printf("%lld\n",ans);
    }

}
