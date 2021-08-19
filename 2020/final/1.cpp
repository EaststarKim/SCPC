#include <bits/stdc++.h>
using namespace std;
int cnt[200010];
long long a[200010],s[200010],ans;
int main(){
    int t,tc,i,j,n,k;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;++i)scanf("%lld",a+i),a[i]+=a[i-1],s[i]=a[i],cnt[i]=0;
        sort(s+1,s+n+1);
        ans=0;
        for(i=1;i<=n;++i){
            if(a[i]==k)++ans;
            j=lower_bound(s+1,s+n+1,a[i]-k)-s;
            if(a[i]-s[j]==k)ans+=cnt[j];
            j=lower_bound(s+1,s+n+1,a[i])-s;
            ++cnt[j];
        }
        printf("Case #%d\n%lld\n",t,ans);
    }
    return 0;
}