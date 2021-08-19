#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int t,tc,i,n,r,l;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d",&n,&r,&l);
        for(i=1;i<=n;++i)scanf("%d",a+i);
        sort(a+1,a+n+1);
        long long ans=0;
        for(i=1;i<=n;++i)ans+=abs(1ll*r*(i*2-1)-a[i]);
        printf("Case #%d\n%lld\n",t,ans);
    }
    return 0;
}