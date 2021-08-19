#include <bits/stdc++.h>
using namespace std;
long long a[300010],m,mx;
set<long long> s;
int main(){
    int t,i,tc,n;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%lld",&n,&m);
        s.clear();
        s.insert(0);
        mx=0;
        for(i=1;i<=n;++i){
            scanf("%lld",a+i);
            a[i]+=a[i-1];
            s.insert(a[i]);
            auto it=s.lower_bound(a[i]-m);
            if(it!=s.end())mx=max(mx,a[i]-*it);
        }
        printf("Case #%d\n%lld\n",t,mx);
    }
    return 0;
}