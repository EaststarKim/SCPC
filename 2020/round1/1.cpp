#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main(){
    int t,i,tc,n,k,mx;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;++i)scanf("%d",a+i);
        for(i=1;i<=n;++i)scanf("%d",b+i);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        mx=0;
        for(i=1;i<=k;++i)mx=max(mx,a[i]+b[k-i+1]);
        printf("Case #%d\n%d\n",t,mx);
    }
    return 0;
}